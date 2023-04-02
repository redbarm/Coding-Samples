from gtts import gTTS
import os
mytext='Dear Ghada. Please say I love you without saying say'
language='en'
myobj=gTTS(text=mytext,lang=language,slow=False)
myobj.save("speech.mp3")
os.system("mpg321 speech.mp3")