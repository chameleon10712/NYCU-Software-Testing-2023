import sys
import copy

class CSS:
# private attributes
	def __check_course_format(self, course):
		if not (type(course) is tuple and len(course) == 4):
			raise TypeError
		if not type(course[0]) is str: # Course name
			raise TypeError
		if not course[1] in self.__workdays: # Day
			raise TypeError
		if not (type(course[2]) is int and type(course[3]) is int and
				1 <= course[2] and course[2] <= 8 and
				1 <= course[3] and course[3] <= 8 and
				course[2] <= course[3]): # Time
			raise TypeError

# public attributes
	def __init__(self):
		self.__workdays = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday']
		self.__courses = []
		pass

	def __str__(self):
		table = [[self.__workdays[i]] + ['|'] * 8 for i in range(len(self.__workdays))]
		for cus in self.__courses:
			for j in range(cus[2], cus[3] + 1):
				table[self.__workdays.index(cus[1])][j] = cus[0]
		s = ''
		for j in range(8):
			for i in range(len(self.__workdays)):
				n = table[i][j].ljust(10, ' ')
				s += n[:10]
			s += '\n'
		return s

	def check_course_exist(self, course): # pragma no cover
#		TODO
#		return True
		sys.exit()

	def add_course(self, course):
		self.__check_course_format(course)
		if self.check_course_exist(course) == False:
			return False
		for cus in self.__courses:
			if not (cus[1] != course[1] or cus[3] < course[2] or cus[2] > course[3]):
				return False
		self.__courses.append(course)
		return True

	def remove_course(self, course):
		self.__check_course_format(course)
		if self.check_course_exist(course) == False:
			return False
		if not course in self.__courses:
			return False
		self.__courses.remove(course)
		return True

	def get_course_list(self):
		return copy.deepcopy(self.__courses)
	
