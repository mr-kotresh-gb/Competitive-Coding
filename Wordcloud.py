import nltk                                                              #to get all the stopwords
nltk.download('stopwords')
from nltk.corpus import stopwords
import wordcloud                                                         #to print wordcloud
from matplotlib import pyplot as plt

def count_words(file1):
    frequencies={}                                                       #dictionary to count the words
    for word in file1:                                                   #get the contents of the file
      text=word.split()                                                  #split words
    for words in text:                                                   #retrieve each word from the list
        if words.isalpha() and words not in stopwords.words('english'):  #checking for constraints
            if words not in frequencies:                                 #if word not already present
                frequencies[words]=1
            frequencies[words]+=1                                        #if word already present
    #return frequencies
    #wordcloud
    cloud = wordcloud.WordCloud()
    cloud.generate_from_frequencies(frequencies)
    return cloud.to_array()

#using matplotlib to get the image
file1=open("C:/Users/APPLE/Desktop/xyz.txt","r")
myimage = count_words(file1)
plt.imshow(myimage, interpolation = 'nearest')
plt.axis('off')
plt.show()
