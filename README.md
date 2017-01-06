# ndb-server

The database server gives you the ability to store a graph of connected nodes.

### Installation

First you need to instal the [ndb](https://github.com/mem-memov/ndb#ndb) library. Then procceed as follows:

```
cd repos/
git clone https://github.com/mem-memov/ndb-server
cd ndb-server/
make
sudo make install
```

### Usage

Start the server in the directory where you are going to keep the data file.

```
cd ~
ndb-server
```

Open a new terminal and start telnet.

```
u@upc ~ $ telnet 127.0.0.1 43152
Trying 127.0.0.1...
Connected to 127.0.0.1.
Escape character is '^]'.
create
1
create
3
create
5
connect 1 3

connect 5 3

read 1
3
intersect 1 5
3
exit
Connection closed by foreign host.
u@upc ~ $ 
```

To stop the server you can press the combination of keys Ctrl+C.

To work with multiple databases start the server in different directiories with different port numbers:
```
cd ~/userdb
ndb-server 4444

```
