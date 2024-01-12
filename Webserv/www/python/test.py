import os
import sys
import time
from datetime import datetime


S_TIME = 60
f_data = "./www/python/data"
myData = dict()

def print_msg(n:int, ms:str, title:str):
    tmp=""
    tmp +=("<!DOCTYPE html>\n")
    tmp +=("<html>\n")
    tmp +=("<head>\n")
    tmp +=("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/my_styles.css\">\n")
    tmp +=("</head>\n")
    tmp +=("<body>\n")
    tmp +=("<div class=\"center-container\">\n")
    tmp +=("<h1>\n")
    if n < 300:
        tmp +=("Hello : " + title)
    else:
        tmp +=("Error")
    tmp +=("\n")
    tmp +=("</h1>\n")
    tmp +=("<p>\n")
    if n > 300:
        tmp +=("Error\n")
        tmp +=("<br>")
        tmp +=(ms)
        tmp +=("<br>")
    else:
        tmp +=(ms)
        # tmp +=("Welcome to your home page!")
        tmp +=("\n")
    tmp +=("</p>\n")
    tmp +=("<h3>\n")
    tmp +=("<a href=\"index.html\">")
    tmp +=("home page")
    tmp +=("</a")
    tmp +=("\n")
    tmp +=("</h3>\n")
    tmp +=("</div>\n")
    tmp +=("</body>\n")
    tmp +=("</html>\n")
    print(tmp)


def find_first_of(s, characters):
    for i, char in enumerate(s):
        if char in characters:
            return i
    return -1

def find_last_of(s, characters):
    for i in range(len(s) - 1, -1, -1):
        if s[i] in characters:
            return i
    return -1

def get_word_by_positions(s, start_pos, end_pos):
    return s[start_pos:end_pos]

def count_equals(s):
    return s.count("=")

def find(input_str, flag):
    global user, password, password1, password2
    if flag == 0:
        user = get_word_by_positions(input_str, find_first_of(input_str, "=") + 1, find_first_of(input_str, "&")) 
        password = get_word_by_positions(input_str, find_last_of(input_str, "=") + 1, len(input_str))
    else:
        user = get_word_by_positions(input_str, find_first_of(input_str, "=") + 1, find_first_of(input_str, "&"))
        password1 = get_word_by_positions(input_str, find_first_of(input_str, "&") + 5, find_last_of(input_str, "&"))
        password2 = get_word_by_positions(input_str, find_last_of(input_str, "=") + 1, len(input_str)) 

def login(input_str):
    ls = input_str.split("&")
    p = ls[0].find("=")
    u_name = ls[0][p + 1:]
    p =ls[1].find("=")
    pwd = ls[1][p + 1:]
    if len(u_name)==0 or len(pwd)==0:
         print("500\nno\nno")
         print_msg(500, "User name or password empty\n","")
        
        #  print("User name or password empty\n")
    elif u_name in myData:
        if myData.get(u_name) == pwd:
              path = "./www/python/session/" +u_name
              c_time = int(time.time())
              r_time = datetime.fromtimestamp(c_time + S_TIME).strftime('%a, %d-%b-%Y %H:%M:%S %Z')
              with open(path, 'w') as f:
                  f.write(str(c_time))
              print("200")
              print(u_name + "-" + str(c_time))
              print(r_time)
              print_msg(200,"Welcome to your home page!",u_name)
            #   print("Hello : " + u_name)
            #   print("Welcome to your website!")
        else:
         print("500\nno\nno")
         print_msg(500,"password wrong\n","")
        #  print("Error password wrong\n")
            
             
    elif u_name not in myData:
         print("500\nno\nno")
         print_msg(500,"You have to make inscription\n","")
        #  print("You have to make inscription\n")

def register(input_str):
    find(input_str, 1)
    if len(user) == 0 or len(password1) == 0 or len(password2) == 0:
        print("500")
        print("no")
        print("no")
        print_msg(500,"empty inputs!\n","")
        # print("Error empty inputs!")
    elif password1 != password2:
        print("500")
        print("no")
        print("no")
        print_msg(500,"password not same!\n","")
    #    print("Error password not same!")
    elif user in myData:
        print("500\nno\nno")
        print_msg(500,"this username already used!\n","")
        # print("no\nno\nError this username already used!")
    else: 
        # if len(myData) == 0:
            with open(f_data, 'a') as file:
                file.write(user)
                file.write("-")
                file.write(password1)
                file.write("\n")
            print("200")
            print("no")
            print("no")
            print_msg(200,"you have registred successfully!\n","")
            # print("you have registred successfully!")

def session(ss):
   if len(ss) == 0:
        print("500")
        print("no\nno")
        print_msg(500,"you haven't login!!\n","")
        return   
   myList = ss.split("-")
   u_name = myList[0]
   u_time = int(myList[1])
   s = str()
   path = "./www/python/session/" + u_name
   if not os.path.exists(path):
        print("500")
        print("no\nno")
        print_msg(500,"you haven't login!!\n","")
   else:
        with open(path, 'r') as file:
            s = file.read()
        delta = int(time.time()) - u_time
        if delta > S_TIME:
            os.remove(path)
            print("500")
            print("no\nno")
            print_msg(500,"session expired!\n","")
        else:
            c_time = int(time.time())
            r_time = datetime.fromtimestamp(c_time + S_TIME).strftime('%a, %d-%b-%Y %H:%M:%S %Z')
            with open(path, 'w') as f:
                f.write(str(c_time))
            print("200")
            print(u_name + "-" + str(c_time))
            print(r_time)
            print_msg(200,"Welcome to your home page!",u_name)
            # print("Hello : " + u_name)
            # print("Welcome to your website!")

def main():
    if sys.argv[1] == "no":
        input_str=""
    else:
        input_str=sys.argv[1]
    if sys.argv[2] == "no":
        ss=""
    else:
        ss=sys.argv[2]
    if not os.path.exists(f_data):
        open(f_data, 'x')
    with open(f_data, 'r') as file:
        for line in file:
            m_list = line.split("-")
            m_list[1] = m_list[1].replace('\n', '')
            myData.update({m_list[0]:m_list[1]})
    if count_equals(input_str) == 2:
        login(input_str)
    elif count_equals(input_str) == 3:
        register(input_str)
    elif count_equals(input_str) == 0:
        session(ss)

if __name__ == '__main__':
    main()
