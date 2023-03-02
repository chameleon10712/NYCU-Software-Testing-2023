The Hunger Games
==================

The nation Utopian select several children each year to fight to death in the annual Hunger Games. Contrast to the old games, the government wants to utilize new technology to assist management. Therefore, the ruler recently asked to develop a random selector app for this significant activity. As a test engineer, the government command you to test for this app.

The procedure of the app:

::

  First, the app will randomly select a child. 
  If the child is selected, the app will keep selecting until it finds a new kid. 
  For those who are selected, the app will write and send mails with the text "Congrats, <name>!".

Since the app is unfinished and may have several bugs, you need to:

::

  (1) Stub the name list of the children.
  (2) Mock the random procedure, and test its correctness.
  (3) Spy on the MailSystem, and check if the mail is correctly written and sent. 
      The total amount of mails shall match the number of selected children.

|

Requirements
-------------

- In ``setUp()``, stub the name list of the children.
  
  - Set name list as "William, Oliver, Henry, Liam"
  - Set the selected ones as "William, Oliver, Henry"
  
- To test class ``Application``, you need to:

  - Mock ``get_random_person()``, return values as follows: "William, Oliver, Henry, Liam".
  - Assure not to select the ones who are already selected.
  - Examine the result of ``select_next_person()`` using ``assertEqual``.

- To test class ``MailSystem``, you need to:
  
  - Finish ``fake_mail()`` and print the mail context.
  - Spy on ``send()`` and ``write()``.
  - Examine the call count of ``send()`` and ``write()`` using ``assertEqual``.

- Notes

  - The real mail system is well structured and complicated, ``app.py`` only write pseudo code to represent it. For MailSystem, you only need to test the logic between the call dependency.


|

Output
--------


.. code::

  python3 -m unittest app_test.py 2>/dev/null
  python3 -m unittest app_test.py -b -v

or

.. code::
  
  python3 -m unittest app_test.py


|

.. raw:: html

    <img src="https://i.imgur.com/BivNibw.png" width="600px">



