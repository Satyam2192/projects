from chatterbot import ChatBot
from chatterbot.trainers import ChatterBotCorpusTrainer

# Create a new chatbot
chatbot = ChatBot(name='My Chatbot')

# Create a trainer for the chatbot
trainer = ChatterBotCorpusTrainer(chatbot)

# Train the chatbot on a corpus of dialogues
trainer.train('chatterbot.corpus.english.greetings',
              'chatterbot.corpus.english.conversations')

# Start a conversation with the chatbot
response = chatbot.get_response('Hello! How are you doing?')
print(response)
