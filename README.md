Assignment Brief
Please read the assignment brief carefully, discuss it with your team and identify any questions. The sooner you ask any questions, the more time you will have to complete your assignment. Ask questions early and often.

Note: the groups for this assignment should be those that your formed in the Lab in Week 1 (check this spreadsheet or the 2022 Study Groups document in the Assessment Area). 


INTRODUCTION
In cybersecurity, a supply-chain attack refers to the tampering with a software or hardware component during its development or manufacture in order to subvert the end product’s security. For example, an attacker might compromise a software developer’s GitHub account in order to introduce security vulnerabilities in the developer’s software projects. Once the produced software is deployed, the attacker can attack the developer’s customers by exploiting the planted vulnerabilities.

See the following links for some high-profile examples of recent supply chain attacks:

Wikipedia - Supply chain attack
Live support service hacked to spread malware in supply chain attack (October 2022)
Mitigating The Risk Of Supply Chain Attacks In The Age Of Cloud Computing (September 2022)
A new type of supply-chain attack with serious consequences is flourishing (March 2021)
New type of supply-chain attack hit Apple, Microsoft and 33 other companies (February 2021)
The year-long rash of supply chain attacks against open source is getting worse (August 2019)
Google confirms that advanced backdoor came preinstalled on Android devices (June 2019)


ASSIGNMENT SPECIFICATION 
In this applied cryptography assignment, you will work as a team to implement two password login (authentication) procedures in C++. One of the login procedures should be secure, but the other should have a covert backdoor that allows you to login as root or any other user on the system without knowing their passwords.

Later in the module, a part of your mark for Assignment 2 will be determined by other teams' (in-)ability to find the backdoor in the subverted procedure that you are developing here.

This means that your team will have to consider operational security: ensure that no one outside of your team has access to your code and your ideas. As part of Assignment 2, only the source code of all subverted login procedures will be distributed. The other teams will not have access to your secure login procedure or its source code, so you do not need to worry about code similarity between your secure and your subverted login procedures.

This assignment can be solved in Ubuntu on the QMB Lab PCs. You may use any other computer and operating system, but it is then your responsibility to ensure that your code also compiles on an Ubuntu configuration as found on the QMB Lab PCs.

Password File Format 
Your login procedures must be able to read files that contain zero or more lines containing a username and a SHA256-hashed password in the format: 

username:SHA256-hashed-password 

For example, a password file might look like this: 

root:5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8 alice:5ef2c394d5b63e4175cd331c74c8453c3e36eb8f47f6d648397ff6c1314fd705 

The SHA256-hashed password for user root in the password file above is “password”. You can verify this by typing the following in the command line:

echo -n "password" | openssl sha256 

In the same way, you can verify that the password for user alice is “mushroom”.

The openssl development library (pre-installed in Ubuntu on the QMB Lab PCs) provides the necessary functions to compute SHA256 hashes (you just need to add the library to your code with #include "openssl/sha.h").

As a starting point for developing your login procedure, you can read the following Stack Overflow post: 

Generate sha256 with OpenSSL and C++


Functionality of the Login Procedures 
Your secure and subverted login procedures must both satisfy the following requirements: 

R1: The login procedure must work with the password file format described in the previous section. 
R2: It must include the authlib.h header file and use the two functions defined therein. 
R3: It must call the function void authenticated(std::string u), where u is the username, whenever a user enters a correct username and password pair. 


In addition, your secure login procedure must satisfy the following requirements: 

R4: It must call the function rejected(std::string u) if an invalid username and password pair was entered. 
R5: It must not call authenticated(std::string u) unless a correct username and password pair for username u was entered. 


It is up to you to decide whether your secure and subverted login procedures offer the user one or more attempts to log in before rejecting and exiting. Your secure and subverted login procedures may offer additional functionalities, which may help disguise backdoors, but shorter backdoored login submission will receive more marks (see the marking scheme for details on this).

The files authlib.h, authlib.cpp, a skeleton login.cpp file, a passwords.txt file and a Makefile are provided in the Assignment 1 ZIP File below.

You must not modify authlib.h or authlib.cpp. You cannot assume that the functions in authlib.cpp will be implemented in the same manner when your code is tested, so do not rely on this as part of the design of your login procedures. Likewise, you can modify the passwords file as you work on your login procedures, but you cannot change the filename or assume anything about the contents of this file when your code is tested, other than they will follow the format above.


SUBMISSION
Submission deadline: 23.59 on Monday 31st October 2022

This assignment must be handed in by one student in each group. Submit your assignment as a single ZIP file named after your group by the deadline.

The ZIP file must contain: 

A file login.cpp. This is the secure password login procedure. Your login.cpp program must:
satisfy requirements R1–R5 above,
compile without warnings when the flags -Wall -pedantic -Wextra are used,
hash the submitted passwords with openssl’s sha256 hash function,
contain fully commented source code.
A file login-subverted.cpp. This is the password login procedure with a backdoor. Your backdoor must:
allow you to login as root or any other user on the system without knowing their passwords,
satisfy requirements R1–R3,
compile without warnings when the flags -Wall -pedantic -Wextra are used,
hash the submitted passwords with openssl’s sha256 hash function,
contain fully commented source code (but comments may be misleading ;).
A file report.pdf. This PDF file documents the vulnerability in your backdoored login procedure. Your report must :
be no more than 1 page and list the team name and team members,
describe the steps to trigger the vulnerability, i.e. how can an attacker login without knowing a user’s password,
show where the vulnerabilities are in the code,
explain why you think that your vulnerabilities are difficult to detect,
A Makefile. This file compiles both your secure and your subverted login procedures.


MARKING SCHEME
See the file Assignment 1 Specification below for the marking scheme. Read the marking scheme before starting any work. 


PEER ASSESSMENT AND TEAMWORK
After the submission, all team members must fill in a peer assessment form at https://peerreview.computing.dundee.ac.uk/.

The marks and feedback resulting from your submission will be your group mark. Peer assessment submissions allow us to determine individual marks as adjustments to the group mark based on the distribution of effort. The online peer reviews system automatically adjusts marks based on how the effort of each team member was assessed by everyone in the team, but these adjustments are manually moderated by the module lead to ensure that they are fair and consensual. Moderation is carried out based on the effort distribution figures but rely heavily on the comments that you provide of each other's work and of the team in general.

Comments allow you to elaborate on any imbalances in the share of the workload that team members took on, any issues that resulted from team members not meeting their commitments, and so forth. They provide justification for any adjustments to individual marks and give us a way to determine that the team is in agreement of the individual contributions.

If you have awarded someone in your team a greater or lesser contribution than others, please provide comments to justify your decision. In doing so, you may wish to reflect upon the following:

were tasks outlined and were these agreed and clear to everyone in the team and when the deadlines were;
did people contribute and complete their tasks to the best of their ability;
where tasks completed on time;
did people attend the team meetings;
did people communicate well and keep each other aware of progress;
were the contributions adequate and to an acceptable standard.


Peer reviews are not meant to be punitive, but rather a way to ensure fairness in the credit that each member of the team receives for the results of collective work. In some cases, for instance, a team member might not be able to contribute for reasons that are beyond their control, so it is only fair that if the rest of the team took on extra work to compensate, they receive a higher mark. Mitigating circumstances then allow for team members that could not contribute equally to the work for reasons beyond their control to have any consequences of this on their individual marks reviewed and rectified by an independent committee.
