import os
import nltk
import string

from nltk.stem.porter import PorterStemmer
from nltk.corpus import stopwords

from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

x = []
file_list = []
file_content = []
file_tokens = []
ps = PorterStemmer()
file_stems = []
stop_words = set(stopwords.words("english"))

""" 
    The tokenize function converts the text to tokens, then the stop words are removed and then the 
    tokens are stemmed.  The stem_tokens requires stop words to be set since tokenize is called from 
    the tfidf function.
"""
def tokenize(text):
    tokens = nltk.word_tokenize(text)
    stems = stem_tokens(tokens, ps)
    return stems

""" stem tokens requires stop_words to be set """
def stem_tokens(tokens, stemmer):
    stems = []
    for token in tokens:
        if token not in stop_words:
            stems.append(stemmer.stem(token))
    return stems

#{"100554newsML.txt", "100593newsML.txt", "100618newsML.txt", "130040newsML.txt", "137871newsML.txt"}
""" This program assumes all .txt files in its interpreted tree are to be processed
    the file list is created, the files tokenized, then stop words are removed and stems located"""
path="/home/chris/Dropbox/MSCS/CAP6776 - Information and Data Retrieval/Project01/hw 1 datasets/"
for files in os.listdir(path):
    if files.endswith('.txt'):
        file_list.append(files)

file_list = sorted(file_list)
print("Read from file list, convert to lower case then remove punctuation:")
for filename in file_list:
    content = open(path+filename).read().lower().translate(dict.fromkeys(string.punctuation))    # convert to lowercase here for ease of processing
    x.append(content)

print("Tokenize: remove stop words and conduct stemming:")
for stuff in x:
    print(tokenize(stuff))

print("Vectorize, removing stop words and tokenize:")
vectorizer = TfidfVectorizer(tokenizer=tokenize, stop_words='english', lowercase=False)

#    print(f)
tfidf = vectorizer.fit_transform(x)

#get word array (feature_names)

words = vectorizer.get_feature_names()

""" Print unsorted document word matrix.
    only use words found in documents ignore sparse array
"""
for c in tfidf.nonzero()[1]:
    print (words[c], ' - ', tfidf[0,c])

print("Document cosine similarity matrix:")

cos_matrix=[]
for r in tfidf:
    cos_matrix.append(cosine_similarity(r, tfidf))

print(file_list)
for n in cos_matrix:
    print(n)