/** \example tcpcliserv/str_cli.cpp
 * The implement of str_cli function in tcp echo client.
 */
#include "str_cli.hpp"

#include <string>

using namespace std;
using namespace mini_socket;

void
str_cli(istream &in, TCPSocket &sock)
{
    string sendline, recvline;
    auto &sockStream = sock.getStream();

    while (getline(in, sendline)) {
        sendline += '\n';
        sock.sendAll(sendline.c_str(), sendline.size());
        getline(sockStream, recvline);
        cout << recvline << endl;
    }
}
