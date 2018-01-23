import os
import nltk
import string
import numpy as py

from nltk.stem.porter import PorterStemmer
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize, sent_tokenize

from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

x = {}
file_list = []
file_content = []
file_tokens = []
ps = PorterStemmer()
file_stems = []
stop_words = set(stopwords.words("english"))

#{"100554newsML.txt", "100593newsML.txt", "100618newsML.txt", "130040newsML.txt", "137871newsML.txt"}
""" This program assumes all .txt files in its interpreted tree are to be processed
    the file list is created, the files tokenized, then stop words are removed and stems located"""
for files in os.listdir("/home/chris/Dropbox/MSCS/CAP6776 - Information and Data Retrieval/Project01/"):
    if files.endswith('.txt'):
        file_list.append(files)

""" 
    The tokenize phase reads from the file, converts the file to lowercase, removes punctuation 
    then tokenizes into sentences then words, the words are then stemmed
"""
def tokenize(text):
    tokens = nltk.word_tokenize(text)
    stems = stem_tokens(tokens, ps)
    return stems

def stem_tokens(tokens, stemmer):
    stems = []
    for token in tokens:
        stems.append(stemmer.stem(token))
    return stems


print("Tokenize:")
for filename in file_list:
    content = open(filename).read().lower().translate(dict.fromkeys(string.punctuation))    # convert to lowercase here for ease of processing
    x[filename] = content
    file_content.append(content)
#    file_content.append(open(filename).read().lower().translate(string.punctuation))    # convert to lowercase here for ease of processing
#    x[filename] =
#    file_content.append(open(filename).read().lower().translate(dict.fromkeys(string.punctuation)))    # convert to lowercase here for ease of processing

for file_data in file_content:
    print(sent_tokenize(file_data))

for file_data in file_content:
    file_tokens.append(word_tokenize(file_data))

file_stems = []
for file_token in file_tokens:
    w_stem = []
    for w in file_token:
#remove stop words and st
        if w not in stop_words:
            w_stem.append(ps.stem(w))
    file_stems.append(w_stem)

print("Remove stop words/stem:")
for w in file_stems:
    print(w)

print("Stems:")
print(file_stems)
#for w in file_stems:
#    print(w)

print("Vectorize:")
vectorizer = TfidfVectorizer(tokenizer=tokenize, stop_words='english', lowercase=False)

#    print(f)
tfidf = vectorizer.fit_transform(x.values())

print(tfidf)

for c in tfidf:
    print (c)


cos_matrix=[]
for r in tfidf:
    cos_matrix.append(cosine_similarity(r, tfidf))

for r in cos_matrix:
    print(r)
    
#sentence = " At eight o'clock on tursday morning Mr. Arthur didn't feel very good. It seems he caught a cold."

#print(sent_tokenize(sentence))

#print(word_tokenize(sentence))