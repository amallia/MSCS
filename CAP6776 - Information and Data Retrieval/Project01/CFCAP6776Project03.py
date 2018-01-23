import os
import nltk
import string
import collections

from nltk.stem.porter import PorterStemmer
from nltk.corpus import stopwords

from sklearn.decomposition import TruncatedSVD
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
from sklearn.cluster import KMeans

from pprint import pprint

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
    stems = [stemmer.stem(token) for token in tokens]
    return stems



path="/home/chris/Dropbox/MSCS/CAP6776 - Information and Data Retrieval/Project03/"
filename="hw4data-docs4sum.txt"
print("Read from file list, convert to lower case then remove punctuation:")
x=[]
with open(path+filename) as f:
    x = f.readlines()
y = [stuff.strip() for stuff in x]

print("Vectorize, removing stop words and tokenize:")
vectorizer = TfidfVectorizer(tokenizer=tokenize, stop_words='english', lowercase=True)
tfidf = vectorizer.fit_transform(y)

print("k-means clustering")
k_means = KMeans(n_clusters=10, max_iter=10000)
k_means.fit(tfidf)

clusters = collections.defaultdict(list)
for index, label in enumerate(k_means.labels_):
    clusters[label].append(index)

#pprint(dict(clusters))
print("cluster centers by proximity to centroid")
centroids = k_means.cluster_centers_.argsort()[:,::-1]

terms = vectorizer.get_feature_names()
#print centroids
print(centroids)
#pprint(dict(centroids))
statements = vectorizer.get_feature_names()
for index in range(10):
    print("Cluster %d: " % index)

    for i in centroids[index, :30]:
        print (' %s ' % terms[i])
 #       print(centroids[index,i])
    print(min(centroids[index]))
 #   print(x[centroids[index,0]], end='\n')
 #   for i in centroids[index, 0]:
 #   print(' %s' %  x[centroids[index,0]], end='\n')
 #   print()

print()
