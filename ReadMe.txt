Darsh Viradiya
2024EE10514
COL106 Long Assignment-2

How to run-

run this script in the "git bash" after downloading and extracting the zip file

change directory to the directory named "LongAssignment2"
	run the command "chmod +x compiler.sh"
	run the command "./compiler.sh"  (if running in bash)
	(if not in bash and bash is installed)  run the command "bash compiler.sh"

if "windows"
	run command "g++ -std=c++17 main_code/*.cpp -Iimplement_files -o socialnet"
	run command "./socialnet.exe"

ADD_USER <username>:

	add a user to the social et simulator

	usernames will be converted to lower cases

	duplicate users and empty username are handled

ADD_FRIEND <username1> <username2>:

	creates friendship between username1 and username2

	self friendship is handled

	both users must exist is handled

	duplicate friendship is not allowed

ADD_POST <username> <content>:

	adds a post for the user

	content can be anything alphabets or numbers

	users existence is checked

	posts are stored in reverse chronology order of time 

LIST_FRIENDS <username>:

	lists all the existing friends of the user

	user existence is checked

SUGGEST_FRIENDS <username> <N>:'

	suggests top N friends for the user

	the output is in sorted order of alphabet

	handles all cases for N<=0 and non existing user

DEGREES_OF_SEPARATION <username1> <username2>:

	gives shortest path between two users

	if path not exist the case is handled

	handles case of non user existence

OUTPUT_POSTS <username> <N>:

	ouputs N recent posts according to time of post

	latest post is showed first

	users existence is checked