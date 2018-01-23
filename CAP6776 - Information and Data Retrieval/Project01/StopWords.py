import os

from nltk.tokenize import sent_tokenize, word_tokenize


file_list = []
file_content = []

#{"100554newsML.txt", "100593newsML.txt", "100618newsML.txt", "130040newsML.txt", "137871newsML.txt"}

for files in os.listdir():
    if files.endswith('.txt'):
        file_list.append(files)

for filename in file_list:
    file_content.append(open(filename).read())

for file_data in file_content:
    print(sent_tokenize(file_data))
    print(word_tokenize(file_data))



sentence = " At eight o'clock on tursday morning Mr. Arthur didn't feel very good. It seems he caught a cold."

print(sent_tokenize(sentence))

print(word_tokenize(sentence))