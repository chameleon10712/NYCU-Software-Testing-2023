Part 1 - Unit Test
=======================

Q1
---

(60%)

Here is a class of course scheduling system called ``CSS`` in
``course_scheduling_system.py``. To be simple, there are five school
days and there are class 1 to 8 in each school day, and we assume a
course is arranged in continuous classes. A course should be represented
as a tuple that contains course name, day, starting class, and ending
class, e.g., ``('Algorithms', 'Monday', 3, 4)``.

There are 5 methods of ``CSS``.

1. ``__str__``: Return the schedule in a formatted way and in the type
   of ``str``. (``str(object)`` returns
   ``type(object).__str__(object)``, which is the “informal” or nicely
   printable string representation of object)
2. ``check_course_exist``: Check whether a course exists
3. ``add_course``: Add a course into the schedule if the course exists
   and doesn’t overlap with the other courses in the schedule.
4. ``remove_course``: Remove a course if it is in the schedule
5. ``get_course_list``: Return a copyed list of courses in the schedule.
   The order will be the same as the order they are added.

However, ``check_course_exist`` hasn’t been implemented yet, but you
want to test the rest of the class ``CSS``. Please write a python unit
test named ``course_scheduling_system_test.py`` to fulfill the the
following requirements and it should run with ``python -m unittest``
and ``python course_scheduling_system_test.py``. Here are some fundamental
requirements first.

-  Please write a test method for each requirement below and name it in
   the form of ``test_q1_x``, e.g., ``test_q1_1``.
-  Don’t access any attribute whose name is starting with double underscore 
   directly, e.g., ``__str__``.
-  Don’t modify ``course_scheduling_system.py`` unless it says so.

**If you don’t know mock, you can change ``check_course_exist`` to
return ``True`` in ``course_scheduling_system.py`` directly and answer
the questions except q1_3 and you will get only 70% points of them.**

q1_1 (5%)
---------

Let ``check_course_exist`` return ``True`` by mocking (**Stub**). Try to
add one course by ``add_course``, check its return value, and verify the
result by ``get_course_list``.

q1_2 (5%)
---------

Let ``check_course_exist`` return ``True`` by mocking. Try to add two
courses overlapping with each other, check its return value, and verify
the result.

q1_3 (5%)
---------

Let ``check_course_exist`` return ``False`` by mocking. Try to add one
course, and check its return value.

q1_4 (10%)
----------

Let ``check_course_exist`` return ``True`` by mocking. Try to add a
invalid course input, and check the Exception raised.

q1_5 (20%)
----------

Let ``check_course_exist`` return ``True`` by mocking. Try to add three
courses that don’t overlapp with each other and then remove the second
one by ``remove_course``, verify the result, and then check the call
count of ``check_course_exist``. Also, try to print out the schedule in
a formatted way.

q1_6 (15%)
----------

Add some more (possibly 0) tests to achieve 100% coverage of
``course_scheduling_system.py``. You can mock ``check_course_exist`` and
use pragma to excluding ``check_course_exist`` from coverage analysis. (If you need more than one test method, please name it as test_q1_6_1, test_q1_6_2, ...)


|

Part 2 - Selenium
=====================

Please write a Python program named ``app.py`` that use Selenium with below options, and fulfill the following requirements.

.. code:: py

   options = Options()
   options.add_argument('--headless')
   options.add_argument('--window-size=1920,1080')
   options.add_argument('--disable-gpu')


Q2-1
------

(15%)

1. Go to `https://docs.python.org/3/tutorial/index.html <https://docs.python.org/3/tutorial/index.html>`_. (2%)
2. Select the language options on the navigation bar (Fig. 1), and choose the ``Traditional Chinese`` option. Note that any selenium operation is legal except for changing the URL directly. (10%)


3. Wait for lanugage translation, then use ``find_element`` to get the title and the first paragraph (Fig. 2). Print the title and the first paragraph. (3%)



Q2-2
------

(15%)

5. Find the search box on the navigation bar (Fig. 3), and send keys to search for ``class``. Note that any selenium operation is legal except for changing the URL directly. (10%)
 

6. Please use `implicit or explicit wait in Selenium <https://selenium-python.readthedocs.io/waits.html>`_ to wait for the searching result (Fig. 4), and print the top five listed titles. Note that you will get no point if you use ``sleep()``. (5%)


|

Part 3 - Continuous Integration
===================================

(10%)

To verify Q1 and Q2, please write a GitHub Action configuration file named ``Midterm-CI.yml`` that includes the following commands.

.. code:: sh

   # Q1
   $ python3 course_scheduling_system_test.py  -v 1>log.txt
   $ cat log.txt
   $ coverage run course_scheduling_system_test.py
   $ coverage report
   
   # Q2
   $ python3 app.py

|



Required Output
----------------

.. raw:: html

    <img src="https://i.imgur.com/BG5VVxz.png" width="800px">

|

.. raw:: html

    <img src="https://i.imgur.com/vtYER9C.png" width="800px">

|

.. raw:: html

    <img src="https://i.imgur.com/Xq7gXjw.png" width="800px">

|

Hint:

- `Locating Elements <https://selenium-python.readthedocs.io/locating-elements.html>`_
- `Selenium Tips: CSS Selectors <https://saucelabs.com/resources/blog/selenium-tips-css-selectors>`_


|



Submission
============

Please submit your Github repo <student_id>-ST-2023  (1) commit URL  (2) github action job URL  to E3

- commit URL

  - refer to Lab 1 submission

- github action job URL

  - refer to Lab 3 submission


|

Reference
===========

Fig. 1

.. raw:: html

    <img src="https://i.imgur.com/tP0cXZS.png" width="600px">

|

Fig. 2

.. raw:: html

    <img src="https://i.imgur.com/VduXjVu.png" width="600px">

|

Fig. 3

.. raw:: html

    <img src="https://i.imgur.com/Y4qq2ug.png" width="600px">

|

Fig. 4

.. raw:: html

    <img src="https://i.imgur.com/bNzmWV4.png" width="600px">



|
