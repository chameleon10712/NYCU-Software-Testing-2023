import random


class MailSystem:
	def write(self, name):
		print('--write mail for ' + name + '--')
		context = 'Congrats, ' + name + '!'
		return context

	def send(self, name, context):
		print('--send mail to ' + name + '--')
		# TODO
		pass


class Application:
	people = []
	selected = []
	mailSystem = MailSystem()

	def __init__(self, people=[], selected=[]):
		(self.people, self.selected) = self.get_names()

	def get_names(self):
		with open("name_list.txt", "r") as f:
			people = f.read().split('\n')
		selected = []
		return (people, selected)
		
	def get_random_person(self):
		i = random.randrange(0, len(self.people))
		return self.people[i]

	def select_next_person(self):
		print('--select next person--')
		if len(self.people) == len(self.selected):
			print('all selected')
			return None
		person = self.get_random_person()
		while person in self.selected:
			person = self.get_random_person()
		self.selected.append(person)
		return person

	def notify_selected(self):
		print('--notify selected--')
		for x in self.selected:
			context = self.mailSystem.write(x)
			self.mailSystem.send(x, context)


if __name__ == "__main__":
	app = Application()
	app.select_next_person()
	app.select_next_person()
	app.select_next_person()
	app.notify_selected()
