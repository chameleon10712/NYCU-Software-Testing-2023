Lab 1 Spec
============

In this Lab, you are going to implement unit test for ``Students``. 


Notes
-------

- Please implement a unit test based on the spec of ``Students`` Class. The given ``Students.py`` is one of the implementation.

  - Spec of the ``Students`` Class

    - ``set_name(name)``: return a non-negative integer as a “unique” id, and store [id, name] pair internally. 

    - ``get_name(id)``: return the corresponding name. 


  - Spec of the ``StudentsTest`` Class 

    - Check whether ``set_name()`` returns a “unique” id.
    - Check whether ``get_name()`` with id returns its corresponding name.
    - Check wether ``get_name()`` with MEX returns "There is no such user".



|


Part 1 - Unit Test
---------------------

- There are four students in the classroom, who are John, Mary, Thomas, and Jane. Please modify ``StudentTest.py`` and add these names to a student object. You need to test for ``set_name`` and ``get_name`` method in Student Class.

- In ``test_1_get_name()``, you have to test for all the valid ids, and an invalid id using mex. 

  - Mex: The mex of a set of integers is the smallest non-negative integer that does not belong to the set.


|


``python3 -m unittest StudentsTest.Test``

or

``python3 -m unittest StudentsTest.py``


.. code::

  OK
  Start set_name test

  0 John
  1 Mary
  2 Thomas
  3 Jane

  Finish set_name test


  Start get_name test

  user_id length =  4
  user_name length =  4 

  id 0 : John
  id 1 : Mary
  id 2 : Thomas
  id 3 : Jane
  id 4 : There is no such user

  Finish get_name test

|

Part 2 - Coverage
-------------------

Please test the coverage of your program. Modify ``Student.py`` and ``StudentTest.py`` to make coverage to 100%.


``pip3 install coverage``

.. code::

  $ coverage run -m unittest StudentsTest.py
  ...


.. code::

  $ coverage report

  Name             Stmts   Miss  Cover
  --------------------------------------
  Students.py           9      0   100%
  StudentsTest.py      27      0   100%
  --------------------------------------
  TOTAL               36      0   100%

|

`reference <https://plainenglish.io/blog/a-quick-intro-to-to-test-coverage-in-python-9bf299711c6c>`_
