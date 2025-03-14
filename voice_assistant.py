import pyttsx3
import speech_recognition as sr
import datetime

engine = pyttsx3.init()

def speak(text):
    engine.say(text)
    engine.runAndWait()

def listen():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        recognizer.adjust_for_ambient_noise(source)  
        audio = recognizer.listen(source)
        try:
            command = recognizer.recognize_google(audio).lower()
            print(f"Recognized: {command}")
            return command
        except sr.UnknownValueError:
            print("Sorry, I didn't catch that.")
            return None
        except sr.RequestError:
            print("Sorry, the service is down.")
            return None

def tell_time():
    current_time = datetime.datetime.now().strftime("%H:%M:%S")
    speak(f"The current time is {current_time}")
    print(f"The current time is {current_time}")  


def main():
    speak("Hello! How can I assist you today?")
    
    while True:
        command = listen()

        if command:
            if 'time' in command:
                tell_time()
            elif 'exit' in command or 'quit' in command:
                speak("Goodbye!")
                break
            else:
                speak("Sorry, I didn't understand that.")

if __name__ == "__main__":
    main()
