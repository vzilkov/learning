#include <iostream>
#include <boost/beast.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>

//using namespace std;
// CMake learning (for OKRs)

const static std::string MAIN_API = "ip-api.com";
const static std::string API_ARGUMENTS = "/json/";

namespace http = boost::beast::http;
class Client
{
  public:
  static std::string getResponse(std::string ip){
    boost::asio::io_context io;
    boost::asio::ip::tcp::resolver resolver(io);
    boost::asio::ip::tcp::socket socket(io);

    boost::asio::connect(socket, resolver.resolve(MAIN_API, "80"));

    http::request<http::string_body> req(http::verb::get, API_ARGUMENTS, 11);

    req.set(http::field::host, MAIN_API);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    http::write(socket, req);

    std::string response;
    {
      boost::beast::flat_buffer buffer;
      http::response<http::dynamic_body> res;
      http::read(socket, buffer, res);
      response = boost::beast::buffers_to_string(res.body().data());
    }
    socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
    return response;
  }
};

int main(void)
{
  std::cout << "Hello!!!" << std::endl;
  Client client;
  std::cout << client.getResponse("http://ip-api.com/json/24.48.0.1") << std::endl;
  // boost::url_view uv("https://gnu.terminalroot.com.br/ip.php");
  // https://ip-api.com/docs/api:json
  
  return 0;
}