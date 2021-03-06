// proto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma warning(push)
#pragma warning(disable: 4018 4146 4244 4251 4267 4305 4355 4800 4996)
#include <protobuf/test.pb.h>
#pragma warning(pop)

std::string build_message()
{
  proto::Msg msg;
  msg.set_greeting("Hello, World!");

  return msg.SerializeAsString();
}

proto::Msg parse_message(const std::string& buffer)
{
  proto::Msg msg;
  if (!msg.ParseFromArray(buffer.data(), static_cast<int>(buffer.length())))
  {
    std::cout << "Failed to parse message." << std::endl;
  }

  return msg;
}

int main()
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  std::cout << "Building message..." << std::endl;
  auto buffer = build_message();
  auto msg = parse_message(buffer);
  std::cout << "Parsed Message: " << msg.greeting() << std::endl;

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();
  return 0;
}

