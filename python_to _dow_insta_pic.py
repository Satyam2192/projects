import requests

# Set the Instagram API endpoint for getting a user's profile picture
url = "https://www.instagram.com/{username}/?__a=1"

# Replace {username} with the actual username of the user whose profile picture you want to download
username = "instagram"

# Make a GET request to the API endpoint
response = requests.get(url.format(username=username))

# Check the status code of the response
if response.status_code == 200:
    # If the request was successful, get the URL of the profile picture from the response
    profile_picture_url = response.json()['graphql']['user']['profile_pic_url_hd']

    # Download the profile picture using the requests library
    picture = requests.get(profile_picture_url)

    # Save the profile picture to a file on your computer
    with open("profile_picture.jpg", "wb") as f:
        f.write(picture.content)
else:
    # If the request was unsuccessful, print an error message
    print("Failed to download profile picture. Check the username and try again.")
