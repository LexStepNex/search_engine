Project "Search engine"

English instructions:
=======================================================================
The program searches for queries (sets of words) in the documents you need, ranks them, sorts the result in descending order and gives you an answer with the maximum number of answers you need.
The requested files should not contain more than 1000 words.
Maximum 1000 queries.
Queries should have at least 1 word and no more than 10 words.

Operating Instructions:
1. Make sure you have transferred all project data to yourself, especially config.json.
1. Fill in the fields of the congig.json file:
	max_responses(optional, default is 5),

	files - add all necessary file paths, initially refers to test files from the resource folder.

3. fill in the fields of the file request.json - requests of interest to you, from 1 to 10 words in the request

4. Run the program.
	The program will check the integrity of the configuration data.
	Then it will ask you to check the integrity of your entered data: file paths, requests
	Follow the instructions in the program.

5. When ready, type “start” to start the program.
6. If you followed all the conditions correctly, at the end you will get the output in the answers.json file,
	and if not, the program will write errors in the form of exceptions.
7. When finished, press Enter to exit the program.

Инструкции по пользованию на русском:
=======================================================================
Программа ищет в необходимых для вас документах запросы(наборы слов), ранжирует их, сортирует результат в порядке убывания и выдаёт ответ с необходимым для вас максимальным количеством ответов.
В запрашиваемых файлах не должно быть больше 1000 слов.
Максимум 1000 запросов.
В запросах должно быть не менее 1 слова и не более 10.

Инструкция по работе:
1. Убедитесь что вы перенесли все данные проекта к себе, особенно config.json.
1. Заполните поля файла congig.json:
	max_responses(по желанию, по умолчанию = 5),

	files - добавьте все необходимые пути к файлам, изначально относится к тестовым из ресурсной папки

2. заполните поля файла request.json - интересующие для вас запросы, от 1 до 10 слов в запросе

3. Запустите программу.
	Программа проверит целостность конфигурационных данных.
	Затем попросит вас проверить целостность ваших введённых данных: пути к файлам, запросы
	Следуйте инструкция в программе.

4. По готовности введите "start" для начала работы программы.
5. Если вы правильно соблюли все условия, то в конце получите вывод в файл answers.json,
	а если нет, то программа напишет ошибки в виде исключений.
6. После завершения нажмите Enter, что бы выйти из программы.
