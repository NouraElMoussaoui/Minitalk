# Minitalk

Minitalk is a simple demonstration of UNIX signals in C. It consists of a server and a client. The server waits for signals, and the client sends signals that represent a string of characters.

## How it works

The server displays its process ID when started. The client takes the server's PID and a string as arguments. It sends the string to the server one character at a time. Each character is sent as a series of SIGUSR1 and SIGUSR2 signals which represent binary 0 and 1 respectively.

The server receives these signals and reconstructs the characters from the binary. It then prints the received characters to the console.

## Usage

1. make

2. Run the server in one terminal using `./server`. It will display its PID.

3. Run the client in another terminal using `./client PID <message>` , passing the server's PID and the string you want to send as arguments. For example: `./client 1234 "Hello, World!"`.

4. The server will print the received string to the console.

## Bonus
  In the bonus part of the Minitalk project, There is  a couple of additional features:

1. **Server Acknowledgment:** After the server has received and printed a message, it sends an acknowledgment signal back to the client. This lets the client know that its message has been received.

2. **Unicode Support:** The client and server have been enhanced to support Unicode characters. This means you can send messages containing characters from various languages and special symbols.In the bonus part of the Minitalk project,

### Usage
     Run `make bonus` in the terminal. This will compile the `client_bonus.c` and `server_bonus.c` files into `client_bonus` and `server_bonus` executables respectively.
  `After compilation, you can run the server and client with ``./server_bonus` and `./client_bonus <PID> <message>`.
