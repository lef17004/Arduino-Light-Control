import socket
def main():
    IP_ADDRESS = "192.168.86.307" #Change to match your ip address
    PORT_NO = 8888
    print("1. Blue") #0, 0, 255
    print("2. Red") #255, 0, 0
    print("3. Green") #0, 255, 0
    print("4. Aqua") #0, 255, 255
    print("5. White") #255, 255, 255
    print("6. Red and Blue") #255, 0, 255
    print("7. Quit")
    end = False
    while not end:
        Message = None

        option = input("Select an option: ")
        if option == "1":
            Message = "blu"
        elif option == "2":
            Message = "red"
        elif option == "3":
            Message = "gre"
        elif option == "4":
            Message = "aqu"
        elif option == "5":
            Message = "whi"
        elif option == "6":
            Message = "r&b"
        elif option == "7":
            print("Goodbye!")
            Message = "whi"
            end = True
        else:
            print("Invalid Input")

        if Message != None:
            Message = str.encode(Message)
            clientSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            clientSock.sendto(Message, (IP_ADDRESS, PORT_NO))
main()
