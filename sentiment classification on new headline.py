#!/usr/bin/env python
# coding: utf-8

# # SENTIMENT CLASSIFICATION ON NEWS HEADLINE

# In[268]:


import pandas as pd
import numpy as np
import re
import nltk
import matplotlib.pyplot as plt
from nltk.corpus import stopwords
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.svm import LinearSVC
import pickle


# # TRAINING DATA
# 

# In[269]:


train = pd.read_csv('C:/Users/vaibh/OneDrive/Desktop/Sentiment_dataset.csv')
print(train.shape)


# In[270]:


train.head()


# In[271]:


train.isnull().any()


# In[272]:


train[train['sentiment'] ==1].head()


# In[273]:


train[train['sentiment'] == 0].head()


# In[274]:


train.groupby('sentiment').describe()


# # REPRESENTATION OF TEXT DATA INTO GRAPH
# 

# In[275]:


from wordcloud import WordCloud
normal_words =' '.join([text for text in train['news_title'][train['sentiment'] == 1]])

wordcloud = WordCloud(background_color = 'green', width=800, height=500, random_state = 0, max_font_size = 110).generate(normal_words)
plt.figure(figsize=(10, 7))
plt.imshow(wordcloud, interpolation="gaussian")
plt.axis('off')
plt.title('The Positive Words')
plt.show()


# In[276]:


negative_words =' '.join([text for text in train['news_title'][train['sentiment'] == 0]])

wordcloud = WordCloud(background_color = 'pink', width=800, height=500, random_state = 0, max_font_size = 110).generate(negative_words)
plt.figure(figsize=(10, 7))
plt.imshow(wordcloud, interpolation="bilinear")
plt.axis('off')
plt.title('The Negative Words')
plt.show()


# In[277]:


tokenized_news = train['news_title'].apply(lambda x: x.split()) 
print(tokenized_news)


# In[278]:


from gensim.models.doc2vec import TaggedDocument


# In[279]:


def add_label(nws):
    output = []
    for i, s in zip(nws.index, nws):
        output.append(TaggedDocument(s, ["news_title_" + str(i)]))
    return output

# label all the news
labeled_news = add_label(tokenized_news)

labeled_news[:6]


# In[280]:


import re
import nltk

nltk.download('stopwords')
from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer


# In[281]:


train_corpus = []

for i in range(0, 848):
  review = re.sub('[^a-zA-Z]', ' ', train['news_title'][i])
  review = review.lower()
  review = review.split()
  
  ps = PorterStemmer()
  

  review = [ps.stem(word) for word in review if not word in set(stopwords.words('english'))]
  
  # joining them back with space
  review = ' '.join(review)
  train_corpus.append(review)


# In[282]:


from sklearn.feature_extraction.text import CountVectorizer

cv = CountVectorizer(max_features = 2853)
x = cv.fit_transform(train_corpus).toarray()
y = train.iloc[:, 1]

print(x.shape)
print(y.shape)


# In[259]:


from sklearn.model_selection import train_test_split

x_train, x_valid, y_train, y_valid = train_test_split(x, y, test_size = 0.25,random_state = 42)


print(x_train.shape)
print(x_valid.shape)
print(y_train.shape)
print(y_valid.shape)


# In[283]:


from sklearn.preprocessing import StandardScaler

sc = StandardScaler()

x_train = sc.fit_transform(x_train)
x_valid = sc.transform(x_valid)


# In[261]:


print(x_train.shape)
print(x_valid.shape)
from sklearn.metrics import confusion_matrix
from sklearn.metrics import f1_score

from sklearn.linear_model import LogisticRegression

model = LogisticRegression(max_iter=2853)
model.fit(x_train, y_train)

y_pred = model.predict(x_valid)

print("Training Accuracy :", model.score(x_train, y_train))


# In[284]:


X=train['news_title']
tfidf=TfidfVectorizer(max_features=2853, ngram_range=(1,2))
X=tfidf.fit_transform(X)
y=train['sentiment']
X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2, random_state=0)
print(X_train.shape)
print(X_test.shape)
clf=LinearSVC()
clf.fit(X_train, y_train)
print("Accuracy :",clf.score(X_test,y_test))
y_pred=clf.predict(X_test)
#confusion matrix
print("f1 score :", f1_score(y_test, y_pred))
cm = confusion_matrix(y_test, y_pred)
print(cm)


# In[285]:


import pickle
pickle.dump(clf, open('my_model.pickle', 'wb'))
pickle.dump(tfidf, open('count_tfid.pickle', 'wb'))


# In[ ]:


x ='Amazon Tribe Wins Lawsuit Against Big Oil, Saving Millions Of Acres Of Rainforest'
vec= tfidf.transform([x])


# # RESULT

# In[ ]:


check=clf.predict(vec)

if check == [1]:
   print("positive")
else:
   print("negative")


# In[292]:


x ='Terrorism suspected in Eilat attack'
vec= tfidf.transform([x])


# In[293]:



check=clf.predict(vec)

if check == [1]:
   print("positive")
else:
   print("negative")


# In[ ]:




