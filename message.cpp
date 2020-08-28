#include "Header.h"

int main() {
	AVL* fanswer = new AVL();
	user t7;
	message t1;
	std::string t2;
	user* t3;
	user* t32;
	user* t11;
	user* t22;
	user* t12;
	user tt;
	int t61;
	int t13;
	int t55;
	std::vector<message> t4;
	std::queue<std::string> t5;
	std::string t51;
	std::string t52;
	std::string t6;
	std::string t62;
	std::string t8;
	std::string t81;
	// starting to read the file 
	std::ifstream in2("users.txt");
	std::ifstream infile("messages.txt");
	std::ifstream in3("friendrequests.txt");
	std::ifstream in4("friendlist.txt");
	std::ifstream in6("elegantlist.txt");
	// users
	while (in2 >> t7.name >> t7.surname >> t7.cn >> t7.pri >> t7.username >> t7.password) {
		fanswer->insert_user2(t7);
	}
	in2.close();
	// friend requests
	while (in3 >> t51 >> t52) {
		t32 = fanswer->check5(t52);
		t32->my.push(t51);
	}
	in3.close();
	// messages
	while (fanswer->is_empty(infile) == false) {
		infile >> t1.us1 >> t2 >> t1.p >> t55;
		t3 = fanswer->check5(t2);
		char ch;
		char* ch2 = new char[t55];
		int i = 0;
		while (infile.get(ch)) {
			ch2[i] = ch;
			i++;
		}
		t1.text = ch2;
		t4 = t3->f.insert_heap(t1);
	}
	// this is for friendlist which basically i read the first element of each line which is the username and then for the rest of the line i out it in the username's list
	while (fanswer->is_empty(in4) == false) {
		in4 >> t6;
		t11 = fanswer->check5(t6);
		in4 >> t61;
		for (int i = 0; i < t61; i++) {
			in4 >> t8;
			t11->fl.push_back(t8);
		}
	}
	in4.close();
	// elegants
	while (fanswer->is_empty(in6) == false) {
		in6 >> t62;
		t22 = fanswer->check5(t62);
		in6 >> t13;
		for (int h = 0; h < t13; h++) {
			in6 >> t81;
			t22->elegants.push_back(t81);
		}
	}
	FILE *outfile = fopen("messages.txt", "a");
	FILE *out3 = fopen("friendrequests.txt", "a");
	FILE *out4 = fopen("friendlist.txt", "a");
	FILE *out6 = fopen("elegantlist.txt", "a");

	user two;
	user* each; // to get the information using check 3 function
	user* each2; // like the above one but for check 5
	user each3;
	user* eachy;
	user eachy2;
	user each4;
	user* each41;
	user* eachtemp;
	int answer; // used for switch
	int answer2; // used for switch
	int answer3; // used for switch
	int answertemp;
	int answertemp2;
	int sizetext;
	std::string answer4;
	std::string answer5;
	int address; // this is for the address of a vector's node
	std::string userName;
	std::string temp2; // this for continue or logoff
	std::string passWord;
	std::string yesno; // to accept or not the friend requests
					   // these two are for keeping the info of the message 
	std::string to;
	std::string to2;
	std::string to3;
	std::string contex;
	std::string texttemp;
	std::string temps1;
	std::string temps2;
	std::string tre;
	std::string queue; // this to show the queue
	std::vector<message> n; // this is for storing the messages to give this vector to the biuld heap function
	message yu; // this to send the message which every node of vector is made out of it
	user x;
	user y;
	user* fg;
	user* fg2;
	user* fg3;
	user* ea;
	std::vector<message> i; // this is for saving the heap after heapify to use it to read the meassages
	std::vector<message> tempt;
	// i needed some new variables to just save the changes in case 4
	std::vector<message> ft;
	std::vector<message> ft2;
	std::vector<message> ft3;
	ft3.push_back(t1);
	to3 = t2;
	infile.close();
	std::string user, pass, nam, sur;
	std::string cell;
	int prio = 1;
	int flag = 0; // i want it to not to show the menu twice :! in while loop for the first time
	int flag2 = 0;
	int flag3 = 0;
	int p;
	// these are for infile iterators
	int c1 = 0;
	int c2 = 2;

	while (true) {
		std::cout << Color(12, "\t\t\t\t\t\t$$ welcome to elegant! $$") << std::endl;
		std::cout << Color(10, "@Powered by Arya Azimi@") << std::endl;
		std::cout << std::endl;
		Color();
		std::cout << "\tWhat's your command: " << std::endl;
		std::cout << "\t\t1) sign in." << std::endl;
		std::cout << "\t\t2) sign up!!" << std::endl;
		std::cout << "\t\t3) exit" << std::endl;

		std::cin >> answer;
		if (answer < 1 || answer>3) {
			while (answer < 1 || answer>3) {
				std::cout << Color(4, "there's no such command!!") << std::endl;
				std::cout << "Try again!!" << std::endl;
				Color();
				std::cin >> answer;
			}
		}
		std::cout << std::endl;
		switch (answer) {
		case 1:
			std::cout << std::string(50, '\n');
			std::cout << "\n\nUser name: ";
			std::cin >> userName;
			std::cout << std::endl;
			std::cout << "\nPassword: ";
			std::cin >> passWord;
			std::cout << std::endl;
			if (userName == "Admin" && passWord == "5014198arv") {
				std::cout << std::string(50, '\n');
				std::cout << Color(12, "\t\t\t\t\t\t$$ Welcome back Arya $$") << std::endl;
				std::cout << Color(10, "\tat your service: ") << std::endl;
				Color();
				std::cout << "\t\t1)list of all users." << std::endl;
				std::cout << "\t\t2)delete user." << std::endl;
				std::cout << "\t\t3)edit user info by cn!." << std::endl;
				std::cout << "\t\t0)logoff" << std::endl;
				std::cin >> answer2;
				if (answer2 == 0) {
					std::cout << std::string(50, '\n');
					break;
				}
				flag = 0;
				while (answer2 != 0) {
					if (flag == 1) {
						std::cout << std::string(50, '\n');
						std::cout << Color(12, "\t\t\t\t\t\t$$ Welcome back Arya $$") << std::endl;
						std::cout << Color(10, "\tat your service: ") << std::endl;
						Color();
						std::cout << "\t\t1)list of all users." << std::endl;
						std::cout << "\t\t2)delete user." << std::endl;
						std::cout << "\t\t3)edit user info by cn!." << std::endl;
						std::cout << "\t\t0)logoff" << std::endl;
						std::cin >> answer2;
					}
					while (answer2 < 0 || answer2 > 4) {
						std::cout << Color(12, "there's no such command!!") << std::endl;
						std::cout << "Try again!!" << std::endl;
						Color();
						std::cin >> answer2;
					}
					std::cout << std::endl;
					switch (answer2) {
					case 1:

						std::cout << std::string(50, '\n');
						std::cout << Color(9, " How do you want to see it?") << std::endl;
						Color();
						std::cout << "1. preorder." << std::endl;
						std::cout << "2. inorder." << std::endl;
						std::cout << "3. postorder." << std::endl;
						std::cin >> answertemp;
						std::cout << std::endl;
						while (answertemp < 1 || answertemp>3) {
							std::cout << Color(12, "wrong input! try again") << std::endl;
							Color();
							std::cin >> answertemp;
							std::cout << std::endl;
						}
						// the main functions :)
						switch (answertemp) {
						case 1:
							fanswer->display_pre();
							break;
						case 2:
							fanswer->display_in();
							break;
						case 3:
							fanswer->display_post();
							break;
						}
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 1;
						break;
					case 2:
						std::cout << std::string(50, '\n');
						std::cout << "which user do you want to delete?(username) " << std::endl;
						std::cin >> user;
						std::cout << std::endl;
						while (fanswer->check2(user) == false) {
							std::cout << Color(4, "there's no such user!!") << std::endl;
							std::cout << Color(12, "maybe try again!") << std::endl;
							std::cin >> user;
							std::cout << std::endl;
						}
						each2 = fanswer->check5(user);
						fanswer->delete_user2(each2);


						std::cout << Color(12, "user just deleted!") << std::endl;
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 1;
						break;
					case 3:
						std::cout << std::string(50, '\n');
						std::cout << Color(12, "What's the number majesty? ") << std::endl;
						Color();
						std::cin >> cell;
						std::cout << std::endl;
						while (fanswer->check66(cell) != true) {
							std::cout << Color(6, "i couldn't find it") << std::endl;
							std::cout << "try agian" << std::endl;
							Color();
							std::cin >> cell;
							std::cout << std::endl;
						}
						std::cout << std::string(50, '\n');
						std::cout << Color(1, "what do you want to change?!") << std::endl;
						Color();
						std::cout << "\t\t1) name" << std::endl;
						std::cout << "\t\t2) surname" << std::endl;
						std::cout << "\t\t3) username" << std::endl;
						std::cout << "\t\t4) password" << std::endl;
						std::cout << "\t\t5) cellphone number" << std::endl;
						std::cout << "\t\t6) priority" << std::endl;
						std::cin >> answer3;
						if (answer3 < 1 || answer3 >6) {
							while (answer3 < 1 || answer3 >6) {
								std::cout << Color(12, "there is no such command!!") << std::endl;
								std::cout << "try again!" << std::endl;
								Color();
								std::cin >> answer3;
							}
						}
						each = fanswer->check88(cell);
						switch (answer3) {
						case 1:
							std::cout << "what's the new name: " << std::endl;
							std::cin >> nam;
							std::cout << std::endl;
							each->name = nam;
							break;
						case 2:
							std::cout << "what's the new surname: " << std::endl;
							std::cin >> sur;
							std::cout << std::endl;
							each->surname = sur;
							break;
						case 3:
							std::cout << "what's the new username: " << std::endl;
							std::cin >> user;
							std::cout << std::endl;
							each3 = fanswer->check7(each->username);
							tt = each3;
							fanswer->delete_user2(each);
							tt.username = user;
							fanswer->insert_user2(tt);
							break;
						case 4:
							std::cout << "what's the new password: " << std::endl;
							std::cin >> pass;
							std::cout << std::endl;
							each->password = pass;
							break;
						case 5:
							std::cout << "what's the new cellphone number: " << std::endl;
							std::cin >> cell;
							std::cout << std::endl;
							each->cn = cell;
							break;
						case 6:
							std::cout << "what's the new priority: " << std::endl;
							std::cin >> prio;
							std::cout << std::endl;
							each->pri = prio;
							break;
						}
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 1;
						break;
					case 4:
						eachy = fanswer->check5("f2");
						eachy2 = fanswer->check7("f2");
						tt = eachy2;

						std::cout << std::string(50, '\n');
						std::cout << "new username: " << std::endl;
						std::cin >> user;
						fanswer->delete_user2(eachy);
						tt.username = user;
						fanswer->insert_user2(tt);
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 1;
						break;
					}
				}
				std::cout << std::string(50, '\n');
				break;
			}
			while (fanswer->check(userName, passWord) == false) {
				std::cout << Color(12, "sorry there's no such account!!") << std::endl;
				Color();
				std::cout << "\n\nUser name: ";
				std::cin >> userName;
				std::cout << std::endl;
				std::cout << "\nPassword: ";
				std::cin >> passWord;
				std::cout << std::endl;
			}
			each3 = fanswer->check3(userName, passWord);
			eachtemp = fanswer->check5(userName);
			std::cout << std::string(50, '\n');
			std::cout << Color(12, "\t\t\t\t\t\t$$ Welcome back ") << userName << " $$" << std::endl;
			if (eachtemp->f.not_empty() == true) {
				std::cout << Color(1, "\t\t-> you have ") << eachtemp->f.num() << " new messages <-" << std::endl;
				Color();
			}
			std::cout << Color(10, "\tat your service: ") << std::endl;
			Color();
			std::cout << "\t\t1)send friend request." << std::endl;
			std::cout << "\t\t2)send message." << std::endl;
			std::cout << "\t\t3)edit last sent message." << std::endl;
			std::cout << "\t\t4)edit your profile." << std::endl;
			std::cout << "\t\t5)upgrade to elegant!" << std::endl;
			std::cout << "\t\t6)show me my messages!" << std::endl;
			std::cout << "\t\t7)show me my friend requests!" << std::endl;
			std::cout << "\t\t8)elegant !" << std::endl;
			std::cout << "\t\t0)logoff." << std::endl;
			std::cin >> answer2;
			if (answer2 == 0) {
				std::cout << std::string(50, '\n');
				break;
			}
			flag = 0;
			while (answer2 != 0) {
				if (flag == 2) {
					std::cout << std::string(50, '\n');
					std::cout << Color(12, "\t\t\t\t\t\t$$ Welcome back ") << userName << " $$" << std::endl;
					if (eachtemp->f.not_empty() == true) {
						std::cout << Color(1, "\t\t-> you have ") << eachtemp->f.num() << " new messages <-" << std::endl;
						Color();
					}
					std::cout << Color(10, "\tat your service: ") << std::endl;
					Color();
					std::cout << "\t\t1)send friend request." << std::endl;
					std::cout << "\t\t2)send message." << std::endl;
					std::cout << "\t\t3)edit last sent message." << std::endl;
					std::cout << "\t\t4)edit your profile." << std::endl;
					std::cout << "\t\t5)upgrade to elegant" << std::endl;
					std::cout << "\t\t6)show me my messages!" << std::endl;
					std::cout << "\t\t7)show me my friend requests!" << std::endl;
					std::cout << "\t\t8)elegant!" << std::endl;
					std::cout << "\t\t0)logoff." << std::endl;
					std::cin >> answer2;
				}
				if (answer2 < 0 || answer2 > 8) {
					while (answer2 < 1 || answer2 > 7) {
						std::cout << Color(4, "there's no such command!!") << std::endl;
						std::cout << "Try again!!" << std::endl;
						Color();
						std::cin >> answer2;
					}
				}
				std::cout << std::endl;
				switch (answer2) {
				case 1:
					std::cout << std::string(50, '\n');
					std::cout << Color(3, "who do you want to send friend request?(username) ") << std::endl;
					Color();
					std::cin >> to;
					std::cout << std::endl;
					while (to == userName) {
						std::cout << Color(9, "wtf! you can't be your own friend yourself!") << std::endl;
						std::cout << Color(12, "try another username: ") << std::endl;
						Color();
						std::cin >> to;
						std::cout << std::endl;
					}
					while (fanswer->check2(to) == false) {
						std::cout << Color(12, "not found!") << std::endl;
						std::cout << "try again!" << std::endl;
						Color();
						std::cin >> to;
						std::cout << std::endl;
					}
					each = fanswer->check5(to);
					each->my.push(userName);

					fprintf(out3, "%s %s\n", userName.c_str(), to.c_str());
					std::cout << Color(6, "friend request sent!!") << std::endl;
					Color();
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 2;
					break;
				case 2:
					std::cout << std::string(50, '\n');
					fg2 = fanswer->check5(userName);
					std::cout << Color(10, "recommended friends(elegants of yours): ") << std::endl;
					Color();
					for (int i = 0; i < fg2->elegants.size(); i++) {
						std::cout << i + 1 << ". " << fg2->elegants[i] << std::endl;
					}
					std::cout << Color(1, "which one do you want to send message?(enter the username and press 0 to send someelse!))") << std::endl;
					Color();
					std::cin >> answer4;
					std::cout << std::endl;
					if (answer4 != "0") {
						while (fanswer->check2(answer4) != true) {
							std::cout << Color(12, "sorry it doesn't exist!!") << std::endl;
							Color();
							std::cin >> answer4;
							std::cout << std::endl;
						}
						while (answer4 == userName) {
							std::cout << Color(9, "wtf! you can't message yourself!") << std::endl;
							std::cout << Color(12, "try another username: ") << std::endl;
							Color();
							std::cin >> answer4;
							std::cout << std::endl;
						}
						while (fanswer->check9(answer4, fg2) == false) {
							std::cout << Color(9, "sorry he/she isn't in your frienfd elegants!") << std::endl;
							std::cout << Color(12, "try another username: ") << std::endl;
							Color();
							std::cin >> answer4;
							std::cout << std::endl;
						}
						to3 = answer4;
						fg = fanswer->check5(answer4);
						std::cout << "what's the text: " << std::endl;
						std::getline(std::cin >> std::ws, contex);
						sizetext = contex.size();
						std::cout << std::endl;
						yu.text = contex;
						yu.us1 = fg2->username;
						yu.p = fg2->pri;
						ft = fg->f.insert_heap(yu);
						fprintf(outfile, "%s %s %d %d %s\n", yu.us1.c_str(), answer4.c_str(), yu.p, sizetext, yu.text.c_str());
						ft3.push_back(yu);
						std::cout << Color(12, "message sent!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 2;
						break;
					}

					std::cout << "who do you want to send (user name): ";
					std::cin >> to2;
					std::cout << std::endl;
					// check for existance
					while (fanswer->check2(to2) == false) {
						std::cout << Color(12, "sorry it doesn't exist!!") << std::endl;
						Color();
						std::cout << "who do you want to send (user name): ";
						std::cin >> to2;
						std::cout << std::endl;
					}
					while (to2 == userName) {
						std::cout << Color(9, "wtf! you can't message yourself!") << std::endl;
						std::cout << Color(12, "try another username: ") << std::endl;
						Color();
						std::cin >> to2;
						std::cout << std::endl;
					}
					// check for friend list
					fg = fanswer->check5(to2);
					std::cout << fg->username << std::endl;

					while (true) {
						for (int i = 0; i < fg2->fl.size(); i++) {
							std::cout << "in my fl: " << fg2->fl[i] << std::endl;
							if (fg2->fl[i] == fg->username) {
								flag3 = 1;
								break;
							}
						}
						if (flag3 == 1) {
							break;
						}
						std::cout << Color(12, "the user isn't in your friend list :) !") << std::endl;
						std::cout << Color(10, "try again!") << std::endl;
						Color();
						std::cin >> to2;
						std::cout << std::endl;
					}
					to3 = to2;
					std::cout << "what's the text: " << std::endl;
					// i used getline to be able to get the spaces as well
					std::getline(std::cin >> std::ws, contex);
					std::cout << std::endl;
					yu.text = contex;
					sizetext = contex.size();
					each3 = fanswer->check3(userName, passWord);
					yu.us1 = each3.username;
					yu.p = each3.pri;
					each2 = fanswer->check5(to2);
					ft = each2->f.insert_heap(yu);
					fprintf(outfile, "%s %s %d %d %s\n", yu.us1.c_str(), to2.c_str(), yu.p, sizetext, yu.text.c_str());
					// i use this to use it for the next case 
					ft3.push_back(yu);

					std::cout << Color(12, "message sent!!") << std::endl;
					Color();
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 2;
					break;
				case 3:
					// the whole idea is to find the last message of the user which we want and then put it the right spot of his/her heap
					std::cout << std::string(50, '\n');
					fg3 = fanswer->check5(userName);
					for (int i = 0; i < ft3.size(); i++) {
						if (ft3[i].us1 == fg3->username) {
							p = i;
						}
					}
					std::cout << Color(2, "the text is: ") << ft3[p].text << std::endl;
					Color();
					ea = fanswer->check5(to3);
					std::cout << Color(9, "what do you want to change it to? ") << std::endl;
					Color();
					std::cin >> texttemp;
					std::cout << std::endl;
					if (ea->f.search_heap(ft3[p].text) < 0) {
						std::cout << Color(12, "sorry! the message is already has been read!! evil laugh!!haha") << std::endl;
						Color();
					}
					else {
						address = ea->f.search_heap(ft3[p].text);
						ea->f.change(address, texttemp);
					}
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 2;
					break;
				case 4:
					std::cout << std::string(50, '\n');
					std::cout << Color(1, "what do you want to change?!") << std::endl;
					Color();
					std::cout << "\t\t1) name" << std::endl;
					std::cout << "\t\t2) surname" << std::endl;
					std::cout << "\t\t3) username" << std::endl;
					std::cout << "\t\t4) password" << std::endl;
					std::cout << "\t\t5) cellphone number" << std::endl;
					std::cout << "\t\t6) priority" << std::endl;
					std::cin >> answer3;
					if (answer3 < 1 || answer3 >6) {
						while (answer3 < 1 || answer3 >6) {
							std::cout << Color(12, "there is no such command!!") << std::endl;
							std::cout << "try again!" << std::endl;
							Color();
							std::cin >> answer3;
						}
					}
					each = fanswer->check5(userName);
					switch (answer3) {
					case 1:
						std::cout << std::string(50, '\n');
						std::cout << "new name: " << std::endl;
						std::cin >> nam;
						each->name = nam;
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 2;
						break;
					case 2:
						std::cout << std::string(50, '\n');
						std::cout << "new surname: " << std::endl;
						std::cin >> sur;
						each->surname = sur;
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 2;
						break;
					case 3:
						each3 = fanswer->check7(each->username);
						tt = each3;
						std::cout << std::string(50, '\n');
						std::cout << "new username: " << std::endl;
						std::cin >> user;
						fanswer->delete_user2(each);
						tt.username = user;
						fanswer->insert_user2(tt);
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 2;
						break;
					case 4:
						std::cout << std::string(50, '\n');
						std::cout << "previous password: " << std::endl;
						std::cin >> pass;
						while (pass != each3.password) {
							std::cout << Color(4, "the password is wrong!!") << std::endl;
							std::cout << "try again!" << std::endl;
							std::cin >> pass;
							Color();
						}
						std::cout << "new password: " << std::endl;
						std::cin >> pass;
						each->password = pass;
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 2;
						break;
					case 5:
						std::cout << std::string(50, '\n');
						std::cout << "new cellphone: " << std::endl;
						std::cin >> cell;
						each->cn = cell;
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << "continue?? (press any key to continue!)" << std::endl;
						std::cin >> temp2;
						flag = 2;
						break;
					case 6:
						std::cout << std::string(50, '\n');
						std::cout << "new priority: " << std::endl;
						std::cin >> prio;
						each->pri = prio;
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 2;
						break;
					}
					std::cout << std::string(50, '\n');
					break;
				case 5:
					std::cout << std::string(50, '\n');
					each = fanswer->check5(userName);
					fprintf(out6, "%s ", each->username.c_str());
					std::cout << Color(5, "your friends are: ") << std::endl;
					Color();
					for (int i = 0; i < each->fl.size(); i++) {
						std::cout << i + 1 << ". " << each->fl[i] << std::endl;
					}
					std::cout << Color(10, "which one do you want to upgrade to elegant?(username)") << std::endl;
					Color();
					std::cin >> temps1;
					std::cout << std::endl;
					while (fanswer->check8(each->fl, temps1) == false) {
						std::cout << Color(12, "wrong input! try again") << std::endl;
						Color();
						std::cin >> temps1;
						std::cout << std::endl;
					}

					each->elegants.push_back(temps1);
					std::cout << temps1 << Color(10, " added to your elegants!") << std::endl;
					Color();
					fprintf(out6, "%d ", each->elegants.size());
					for (int i = 0; i < each->elegants.size(); i++) {
						fprintf(out6, "%s ", each->elegants[i].c_str());
					}
					fprintf(out6, "\n");
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 2;
					break;
				case 6:
					std::cout << std::string(50, '\n');
					each41 = fanswer->check5(userName);
					each41->f.dis_heap();
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					each41->f.delete_heap();
					flag = 2;
					break;
				case 7:
					std::cout << std::string(50, '\n');
					each2 = fanswer->check5(userName);

					std::cout << Color(10, "the friend requests are: ") << std::endl;
					Color();
					while (!each2->my.empty()) {
						tre = each2->my.get_front();
						fg = fanswer->check5(tre);
						// this is for not getting two requests from one person
						if (fanswer->check10(each2->my.get_front(), each2->fl) == true) {
							each2->my.pop();
						}
						if (each2->my.empty() == true) {
							break;
						}
						std::cout << each2->my.get_front() << std::endl;
						std::cout << Color(1, "(y/n) ?") << std::endl;
						Color();
						std::cin >> yesno;
						std::cout << std::endl;
						while (yesno != "y" && yesno != "n") {
							std::cout << Color(12, "wrong input! try again") << std::endl;
							std::cin >> yesno;
							std::cout << std::endl;
						}
						if (yesno == "y") {
							fg->fl.push_back(each2->username);

							fprintf(out4, "%s ", each2->username.c_str());
							for (int i = 0; i < fg->fl.size(); i++) {
								std::cout << "in his fl: " << std::endl;
								std::cout << fg->fl[i] << std::endl;
							}
							each2->fl.push_back(each2->my.get_front());
							fprintf(out4, "%d ", each2->fl.size());
							for (int i = 0; i < each2->fl.size(); i++) {
								fprintf(out4, "%s ", each2->fl[i].c_str());
							}
							fprintf(out4, "\n");
							// for both in friend list
							fprintf(out4, "%s ", fg->username.c_str());
							fprintf(out4, "%d ", fg->fl.size());
							for (int i = 0; i < fg->fl.size(); i++) {
								fprintf(out4, "%s ", fg->fl[i].c_str());
							}
							fprintf(out4, "\n");
							for (int j = 0; j < each2->fl.size(); j++) {
								std::cout << "in my fl: " << each2->fl[j] << std::endl;
							}
							each2->my.pop();
						}
						else {
							each2->my.pop();
							std::cout << Color(12, "rejected!! harsh!") << std::endl;
						}
					}
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 2;
					break;
				case 8:
					std::cout << std::string(50, '\n');
					std::cout << Color(10, "whoes do you want to see friend list!! ") << std::endl;
					Color();
					std::cin >> temps2;
					std::cout << std::endl;
					while (fanswer->check2(temps2) == false) {
						std::cout << Color(12, "sorry there is no shuch account! try another user!") << std::endl;
						Color();
						std::cin >> temps2;
						std::cout << std::endl;
					}
					each = fanswer->check5(temps2);
					while (fanswer->check9(userName, each) == false) {
						std::cout << Color(12, "sorry you're not in the elegant list! try another user!") << std::endl;
						Color();
						std::cin >> temps2;
						std::cout << std::endl;
					}
					std::cout << each->username << Color(10, "'s friends are: ") << std::endl;
					Color();
					for (int j = 0; j < each->fl.size(); j++) {
						std::cout << each->fl[j] << Color(9, ", ");
						Color();
					}
					std::cout << std::endl;
					std::cout << Color(12, "do you want to send message to any of those?(press n for no!)") << std::endl;
					Color();
					std::cin >> answer4;
					std::cout << std::endl;
					if (answer4 != "n") {
						std::cout << Color(10, "which one you want to message?!") << std::endl;
						Color();
						std::cin >> answer4;
						std::cout << std::endl;
						while (fanswer->check10(answer4, each->fl) == false) {
							std::cout << Color(12, "sorry the user which you choosed isn't in ") << each->username << " list! try another user!" << std::endl;
							Color();
							std::cin >> answer4;
							std::cout << std::endl;
						}
						while (answer4 == userName) {
							std::cout << Color(9, "wtf! you can't message yourself!") << std::endl;
							std::cout << Color(12, "try another username: ") << std::endl;
							Color();
							std::cin >> to2;
							std::cout << std::endl;
						}
						std::cout << "what's the text: " << std::endl;
						std::getline(std::cin >> std::ws, contex);
						std::cout << std::endl;
						each = fanswer->check5(userName);
						yu.text = contex;
						yu.us1 = each->username;
						yu.p = each->pri;
						each2 = fanswer->check5(answer4);
						ft = each2->f.insert_heap(yu);

						std::cout << Color(12, "message sent!!") << std::endl;
						Color();
					}
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 2;
					break;
				}
			}
			std::cout << std::string(50, '\n');
			break;
		case 2:
			std::cout << std::string(50, '\n');
			std::cout << Color(13, "\n\tEnter your name: ");
			std::cin >> two.name;
			std::cout << std::endl;
			while (fanswer->check11(two.name) == false) {
				std::cout << Color(12, "wrong input! try again!") << std::endl;
				Color();
				std::cin >> two.name;
				std::cout << std::endl;
			}
			std::cout << Color(13, "\n\tEnter your surname: ");
			std::cin >> two.surname;
			std::cout << std::endl;
			while (fanswer->check11(two.surname) == false) {
				std::cout << Color(12, "wrong input! try again!") << std::endl;
				Color();
				std::cin >> two.surname;
				std::cout << std::endl;
			}
			std::cout << Color(13, "\n\tEnter your cellphone number: ");
			std::cin >> two.cn;
			std::cout << std::endl;
			while (two.cn.size() != 11) {
				std::cout << Color(12, "it should be 11 figures so try again!") << std::endl;
				Color();
				std::cin >> two.cn;
				std::cout << std::endl;
			}

			std::cout << Color(13, "\n\tEnter your priority(1-10): ");
			std::cin >> two.pri;
			while (two.pri < 1 || two.pri>10) {
				std::cout << Color(12, "wrong input!!") << std::endl;
				Color();
				std::cin >> two.pri;
			}
			std::cout << std::endl;
			std::cout << Color(13, "\n\tEnter your username: ");
			std::cin >> two.username;
			std::cout << std::endl;
			while (fanswer->check12(two.username) == false) {
				std::cout << Color(6, "wrong username!") << std::endl;
				Color();
				std::cin >> two.username;
				std::cout << std::endl;
			}
			std::cout << Color(13, "\n\tEnter your password: ");
			std::cin >> two.password;
			std::cout << std::endl;
			while (two.password.size() < 5) {
				std::cout << Color(12, "it should be at least 5 figures so try again!") << std::endl;
				std::cin >> two.password;
				std::cout << std::endl;
			}
			Color();
			while (fanswer->check4(two.cn)) {
				std::cout << Color(3, "Sorry this phone number is already has been used!") << std::endl;
				Color();
				std::cout << "\n\tEnter your cellphone number: ";
				std::cin >> two.cn;
				std::cout << std::endl;
			}
			while (fanswer->check2(two.username) == true) {
				std::cout << Color(3, "Sorry this username is already taken!") << std::endl;
				Color();
				std::cout << "\n\tEnter your username: ";
				std::cin >> two.username;
				std::cout << std::endl;
			}
			//fprintf(out2, "%s %s %s %d %s %s\n", two.name.c_str(), two.surname.c_str(), two.cn.c_str(), two.pri, two.username.c_str(), two.password.c_str());
			// inserting the member into the tree 
			fanswer->insert_user2(two);


			std::cout << std::string(50, '\n');
			std::cout << Color(13, "congrats! now you're a member of elegant family :)") << std::endl;
			std::cout << std::endl;
			std::cout << Color(1, "now enter your inputs again to sign into your account!") << std::endl;
			Color();
			std::cout << "\n\nUser name: ";
			std::cin >> userName;
			std::cout << std::endl;
			std::cout << "\nPassword: ";
			std::cin >> passWord;
			std::cout << std::endl;
			while (fanswer->check(userName, passWord) != true) {
				std::cout << Color(6, "it's wrong") << std::endl;
				Color();
				std::cout << "\n\nUser name: ";
				std::cin >> userName;
				std::cout << std::endl;
				std::cout << "\nPassword: ";
				std::cin >> passWord;
				std::cout << std::endl;
			}
			each3 = fanswer->check3(userName, passWord);
			eachtemp = fanswer->check5(userName);
			std::cout << std::string(50, '\n');

			std::cout << Color(12, "\t\t\t\t\t\t$$ Welcome back ") << userName << " $$" << std::endl;
			if (eachtemp->f.not_empty() == true) {
				std::cout << Color(1, "\t\t-> you have ") << eachtemp->f.num() << " new messages <-" << std::endl;
				Color();
			}
			std::cout << Color(10, "\tat your service: ") << std::endl;
			Color();
			std::cout << "\t\t1)send friend request." << std::endl;
			std::cout << "\t\t2)send message." << std::endl;
			std::cout << "\t\t3)edit last sent message." << std::endl;
			std::cout << "\t\t4)edit your profile." << std::endl;
			std::cout << "\t\t5)upgrade to elegant" << std::endl;
			std::cout << "\t\t6)show me my messages!" << std::endl;
			std::cout << "\t\t7)show me my friend requests!" << std::endl;
			std::cout << "\t\t8)elegeant!" << std::endl;
			std::cout << "\t\t0)logoff." << std::endl;
			std::cin >> answer2;
			if (answer2 == 0) {
				std::cout << std::string(50, '\n');
				break;
			}
			flag = 0;
			while (answer2 != 0) {
				if (flag == 3) {
					std::cout << std::string(50, '\n');

					std::cout << Color(12, "\t\t\t\t\t\t$$ Welcome back ") << userName << " $$" << std::endl;
					if (eachtemp->f.not_empty() == true) {
						std::cout << Color(1, "\t\t-> you have ") << eachtemp->f.num() << " new messages <-" << std::endl;
						Color();
					}
					std::cout << Color(10, "\tat your service: ") << std::endl;
					Color();
					std::cout << "\t\t1)send friend request." << std::endl;
					std::cout << "\t\t2)send message." << std::endl;
					std::cout << "\t\t3)edit last sent message." << std::endl;
					std::cout << "\t\t4)edit your profile." << std::endl;
					std::cout << "\t\t5)upgrade to elegant" << std::endl;
					std::cout << "\t\t6)show me my messages!" << std::endl;
					std::cout << "\t\t7)show me my friend requests!" << std::endl;
					std::cout << "\t\t8)elegant!" << std::endl;
					std::cout << "\t\t0)logoff." << std::endl;
					std::cin >> answer2;
				}
				while (answer2 < 0 || answer2 > 8) {
					std::cout << Color(12, "there's no such command!!") << std::endl;
					std::cout << "Try again!!" << std::endl;
					Color();
					std::cin >> answer2;
				}
				std::cout << std::endl;
				switch (answer2) {
				case 1:
					std::cout << std::string(50, '\n');
					std::cout << Color(3, "who do you want to send friend request?(username) ") << std::endl;
					Color();
					std::cin >> to;
					std::cout << std::endl;
					while (to == userName) {
						std::cout << Color(9, "wtf! you can't be your own friend yourself!") << std::endl;
						std::cout << Color(12, "try another username: ") << std::endl;
						Color();
						std::cin >> to;
						std::cout << std::endl;
					}
					while (fanswer->check2(to) == false) {
						std::cout << Color(12, "not found!") << std::endl;
						std::cout << "try again!" << std::endl;
						Color();
						std::cin >> to;
						std::cout << std::endl;
					}
					each = fanswer->check5(to);
					each->my.push(userName);

					fprintf(out3, "%s %s\n", userName.c_str(), to.c_str());
					std::cout << Color(6, "friend request sent!!") << std::endl;
					Color();
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 3;
					break;
				case 2:
					std::cout << std::string(50, '\n');
					fg2 = fanswer->check5(userName);
					std::cout << Color(10, "recommended friends(elegants of yours): ") << std::endl;
					Color();
					for (int i = 0; i < fg2->elegants.size(); i++) {
						std::cout << i + 1 << ". " << fg2->elegants[i] << std::endl;
					}
					std::cout << Color(1, "which one do you want to send message?(enter the username and press 0 to send someelse!))") << std::endl;
					Color();
					std::cin >> answer4;
					std::cout << std::endl;
					if (answer4 != "0") {
						while (fanswer->check2(answer4) != true) {
							std::cout << Color(12, "sorry it doesn't exist!!") << std::endl;
							Color();
							std::cin >> answer4;
							std::cout << std::endl;
						}
						while (answer4 == userName) {
							std::cout << Color(9, "wtf! you can't message yourself!") << std::endl;
							std::cout << Color(12, "try another username: ") << std::endl;
							Color();
							std::cin >> answer4;
							std::cout << std::endl;
						}
						while (fanswer->check9(answer4, fg2) == false) {
							std::cout << Color(9, "sorry he/she isn't in your frienfd elegants!") << std::endl;
							std::cout << Color(12, "try another username: ") << std::endl;
							Color();
							std::cin >> answer4;
							std::cout << std::endl;
						}
						to3 = answer4;
						fg = fanswer->check5(answer4);
						std::cout << "what's the text: " << std::endl;
						std::getline(std::cin >> std::ws, contex);
						std::cout << std::endl;
						sizetext = contex.size();
						yu.text = contex;
						yu.us1 = fg2->username;
						yu.p = fg2->pri;
						ft = fg->f.insert_heap(yu);
						fprintf(outfile, "%s %s %d %d %s\n", yu.us1.c_str(), answer4.c_str(), yu.p, sizetext, yu.text.c_str());
						ft3.push_back(yu);
						std::cout << Color(12, "message sent!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 2;
						break;
					}

					std::cout << "who do you want to send (user name): ";
					std::cin >> to2;
					std::cout << std::endl;
					// check for existance
					while (fanswer->check2(to2) == false) {
						std::cout << Color(12, "sorry it doesn't exist!!") << std::endl;
						Color();
						std::cout << "who do you want to send (user name): ";
						std::cin >> to2;
						std::cout << std::endl;
					}
					while (to2 == userName) {
						std::cout << Color(9, "wtf! you can't message yourself!") << std::endl;
						std::cout << Color(12, "try another username: ") << std::endl;
						Color();
						std::cin >> to2;
						std::cout << std::endl;
					}
					// check for friend list
					fg = fanswer->check5(to2);

					while (true) {
						for (int i = 0; i < fg2->fl.size(); i++) {
							std::cout << "in my fl: " << fg2->fl[i] << std::endl;
							if (fg2->fl[i] == fg->username) {
								flag3 = 1;
								break;
							}
						}
						if (flag3 == 1) {
							break;
						}
						std::cout << Color(12, "the user isn't in your friend list :) !") << std::endl;
						std::cout << Color(10, "try again!") << std::endl;
						Color();
						std::cin >> to2;
						std::cout << std::endl;
					}

					to3 = to2;
					std::cout << "what's the text: " << std::endl;
					// iused getline to be able to get the spaces as well
					std::getline(std::cin >> std::ws, contex);
					std::cout << std::endl;
					yu.text = contex;
					sizetext = contex.size();
					each3 = fanswer->check3(userName, passWord);
					yu.us1 = each3.username;
					yu.p = each3.pri;
					each2 = fanswer->check5(to2);
					ft = each2->f.insert_heap(yu);
					fprintf(outfile, "%s %s %d %d %s\n", yu.us1.c_str(), to2.c_str(), yu.p, sizetext, yu.text.c_str());
					// i use this to use it for the next case 
					ft3.push_back(yu);

					std::cout << Color(12, "message sent!!") << std::endl;
					Color();
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 3;
					break;
				case 3:
					std::cout << std::string(50, '\n');
					fg3 = fanswer->check5(userName);
					for (int i = 0; i < ft3.size(); i++) {
						if (ft3[i].us1 == fg3->username) {
							p = i;
						}
					}
					std::cout << Color(2, "the text is: ") << ft3[p].text << std::endl;
					Color();
					ea = fanswer->check5(to3);
					std::cout << Color(9, "what do you want to change it to? ") << std::endl;
					Color();
					std::cin >> texttemp;
					std::cout << std::endl;
					if (ea->f.search_heap(ft3[p].text) < 0) {
						std::cout << Color(12, "sorry! the message is already has been read!! evil laugh!!haha") << std::endl;
						Color();
					}
					else {
						address = ea->f.search_heap(ft3[p].text);
						ea->f.change(address, texttemp);
					}
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 3;
					break;
				case 4:
					std::cout << std::string(50, '\n');
					std::cout << Color(1, "what do you want to change?!") << std::endl;
					Color();
					std::cout << "\t\t1) name" << std::endl;
					std::cout << "\t\t2) surname" << std::endl;
					std::cout << "\t\t3) username" << std::endl;
					std::cout << "\t\t4) password" << std::endl;
					std::cout << "\t\t5) cellphone number" << std::endl;
					std::cout << "\t\t6) priority" << std::endl;
					std::cin >> answer3;
					if (answer3 < 1 || answer3 >6) {
						while (answer3 < 1 || answer3 >6) {
							std::cout << Color(12, "there is no such command!!") << std::endl;
							std::cout << "try again!" << std::endl;
							Color();
							std::cin >> answer3;
						}
					}
					each = fanswer->check5(userName);
					switch (answer3) {
					case 1:
						std::cout << std::string(50, '\n');
						std::cout << "new name: " << std::endl;
						std::cin >> nam;
						each->name = nam;
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 3;
						break;
					case 2:
						std::cout << std::string(50, '\n');
						std::cout << "new surname: " << std::endl;
						std::cin >> sur;
						each->surname = sur;
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 3;
						break;
					case 3:
						each3 = fanswer->check7(each->username);
						tt = each3;
						std::cout << std::string(50, '\n');
						std::cout << "new username: " << std::endl;
						std::cin >> user;
						fanswer->delete_user2(each);
						tt.username = user;
						fanswer->insert_user2(tt);
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 3;
						break;
					case 4:
						std::cout << std::string(50, '\n');
						std::cout << "previous password: " << std::endl;
						std::cin >> pass;
						while (pass != each3.password) {
							std::cout << Color(4, "the password is wrong!!") << std::endl;
							std::cout << "try again!" << std::endl;
							std::cin >> pass;
							Color();
						}
						std::cout << "new password: " << std::endl;
						std::cin >> pass;
						each->password = pass;
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 3;
						break;
					case 5:
						std::cout << std::string(50, '\n');
						std::cout << "new cellphone: " << std::endl;
						std::cin >> cell;
						each->cn = cell;
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << "continue?? (press any key to continue!)" << std::endl;
						std::cin >> temp2;
						flag = 3;
						break;
					case 6:
						std::cout << std::string(50, '\n');
						std::cout << "new priority: " << std::endl;
						std::cin >> prio;
						each->pri = prio;
						std::cout << std::endl;
						std::cout << Color(4, "complete!!") << std::endl;
						Color();
						std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
						Color();
						std::cin >> temp2;
						flag = 3;
						break;
					}
					std::cout << std::string(50, '\n');
					break;
				case 5:
					std::cout << std::string(50, '\n');
					each = fanswer->check5(userName);
					fprintf(out6, "%s ", each->username.c_str());
					std::cout << Color(5, "your friends are: ") << std::endl;
					Color();
					for (int i = 0; i < each->fl.size(); i++) {
						std::cout << i + 1 << ". " << each->fl[i] << std::endl;
					}
					std::cout << Color(10, "which one do you want to upgrade to elegant?(username)") << std::endl;
					Color();
					std::cin >> temps1;
					std::cout << std::endl;
					while (fanswer->check8(each->fl, temps1) == false) {
						std::cout << Color(12, "wrong input! try again") << std::endl;
						Color();
						std::cin >> temps1;
						std::cout << std::endl;
					}

					each->elegants.push_back(temps1);
					std::cout << temps1 << Color(10, " added to your elegants!") << std::endl;
					Color();
					fprintf(out6, "%d ", each->elegants.size());
					for (int i = 0; i < each->elegants.size(); i++) {
						fprintf(out6, "%s ", each->elegants[i].c_str());
					}
					fprintf(out6, "\n");
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 3;
					break;
				case 6:
					std::cout << std::string(50, '\n');
					each41 = fanswer->check5(userName);
					each41->f.dis_heap();
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					each41->f.delete_heap();
					flag = 3;
					break;
				case 7:
					std::cout << std::string(50, '\n');
					each2 = fanswer->check5(userName);

					std::cout << Color(10, "the friend requests are: ") << std::endl;
					Color();
					while (!each2->my.empty()) {
						tre = each2->my.get_front();
						fg = fanswer->check5(tre);
						// this is for not getting two requests from one person
						if (fanswer->check10(each2->my.get_front(), each2->fl) == true) {
							each2->my.pop();
						}
						if (each2->my.empty() == true) {
							break;
						}
						std::cout << each2->my.get_front() << std::endl;
						std::cout << Color(1, "(y/n) ?") << std::endl;
						Color();
						std::cin >> yesno;
						std::cout << std::endl;
						while (yesno != "y" && yesno != "n") {
							std::cout << Color(12, "wrong input! try again") << std::endl;
							std::cin >> yesno;
							std::cout << std::endl;
						}
						if (yesno == "y") {
							fg->fl.push_back(each2->username);

							fprintf(out4, "%s ", each2->username.c_str());
							for (int i = 0; i < fg->fl.size(); i++) {
								std::cout << "in his fl: " << std::endl;
								std::cout << fg->fl[i] << std::endl;
							}
							each2->fl.push_back(each2->my.get_front());
							fprintf(out4, "%d ", each2->fl.size());
							for (int i = 0; i < each2->fl.size(); i++) {
								fprintf(out4, "%s ", each2->fl[i].c_str());
							}
							fprintf(out4, "\n");
							// for both in friend list
							fprintf(out4, "%s ", fg->username.c_str());
							fprintf(out4, "%d ", fg->fl.size());
							for (int i = 0; i < fg->fl.size(); i++) {
								fprintf(out4, "%s ", fg->fl[i].c_str());
							}
							fprintf(out4, "\n");
							for (int j = 0; j < each2->fl.size(); j++) {
								std::cout << "in my fl: " << each2->fl[j] << std::endl;
							}
							each2->my.pop();
						}
						else {
							each2->my.pop();
							std::cout << Color(12, "rejected!! harsh!") << std::endl;
						}
					}
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 3;
					break;
				case 8:
					std::cout << std::string(50, '\n');
					std::cout << Color(10, "whoes do you want to see friend list!! ") << std::endl;
					Color();
					std::cin >> temps2;
					std::cout << std::endl;
					while (fanswer->check2(temps2) == false) {
						std::cout << Color(12, "sorry there is no shuch account! try another user!") << std::endl;
						Color();
						std::cin >> temps2;
						std::cout << std::endl;
					}
					each = fanswer->check5(temps2);
					while (fanswer->check9(userName, each) == false) {
						std::cout << Color(12, "sorry you're not in the elegant list! try another user!") << std::endl;
						Color();
						std::cin >> temps2;
						std::cout << std::endl;
					}
					std::cout << each->username << Color(10, "'s friends are: ") << std::endl;
					Color();
					for (int j = 0; j < each->fl.size(); j++) {
						std::cout << each->fl[j] << Color(9, ", ");
						Color();
					}
					std::cout << std::endl;
					std::cout << Color(12, "do you want to send message to any of those?(press n for no!)") << std::endl;
					Color();
					std::cin >> answer4;
					std::cout << std::endl;
					if (answer4 != "n") {
						std::cout << Color(10, "which one you want to message?!") << std::endl;
						Color();
						std::cin >> answer4;
						std::cout << std::endl;
						while (fanswer->check10(answer4, each->fl) == false) {
							std::cout << Color(12, "sorry the user which you choosed isn't in ") << each->username << " list! try another user!" << std::endl;
							Color();
							std::cin >> answer4;
							std::cout << std::endl;
						}
						while (answer4 == userName) {
							std::cout << Color(9, "wtf! you can't message yourself!") << std::endl;
							std::cout << Color(12, "try another username: ") << std::endl;
							Color();
							std::cin >> to2;
							std::cout << std::endl;
						}
						std::cout << "what's the text: " << std::endl;
						std::getline(std::cin >> std::ws, contex);
						std::cout << std::endl;
						each = fanswer->check5(userName);
						yu.text = contex;
						yu.us1 = each->username;
						yu.p = each->pri;
						each2 = fanswer->check5(answer4);
						ft = each2->f.insert_heap(yu);

						std::cout << Color(12, "message sent!!") << std::endl;
						Color();
					}
					std::cout << Color(4, "continue?? (press any key to continue!)") << std::endl;
					Color();
					std::cin >> temp2;
					flag = 3;
					break;
				}
			}
			std::cout << std::string(50, '\n');
			break;

		case 3:
			std::ofstream out2("users.txt");
			fanswer->pre_file2(out2);
			out2.close();
			fclose(outfile);
			fclose(out3);
			fclose(out4);
			exit(EXIT_FAILURE); // exit(1);
		}
	}
}