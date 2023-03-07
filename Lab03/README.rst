Lab 3
========

Part 1

For the following functions, please use specific Python Exception Type for comparison. 
For instance, use TypeError other than Exception.

``test_add()``, ``test_divide()``, ``test_sqrt()``, ``test_exp()``


For each test, please 

- use for loop to test 5 sets of valid input. Use assertEqual to check the output.
- test a set of invalid input. Use assertRaises to compare the output.


Part 2

Please implement ``Lab03-CI.yml``. Achieve the following goals.

- Use ``python3 -m unittest calculator_test.py -v`` as command to execute Lab 3 program.
- Use ``flake8 calculator_test.py`` to check your code, modify your code to follow the PEP8 coding style.

|

--  

|

Part 1

以下 function，請與精確的 Exception Type 進行比較，例如使用 ``TypeError`` 而非 ``Exception``


``test_add()``, ``test_divide()``, ``test_sqrt()``, ``test_exp()``


- 請使用 for loop 輸入五組合法參數組合，並使用 assertEqual 去檢查答案
- 請各輸入一組非法參數組合，並使用 assertRaises 去比對結果


|

Part 2


請完成 ``Lab03-CI.yml``，並達到下列目標

- 使用 ``python3 -m unittest calculator_test.py -v`` 執行 Lab3 程式
- 使用下列指令檢測 ``calculator_test.py``，並修改程式碼以符合規範

  - ``flake8 calculator_test.py``
  
- 寫法請參考 ``Lab02-CI.yml``
