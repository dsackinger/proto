# proto
Simple Protobuf program that includes an MSBuild tool for building proto files

The program itself is a simple Hello, World! program that uses Google Protobuf.

In the msvc directory, the following files define a custom tool:
* protoc.xml - defines the UI for the tool
* protoc.props - defines the properties for our protoc tool
* protoc.targets - defines the build process

The tool is pretty simplistic and only supports cpp_out at the current time, but it should track dependencies correctly.

Additions or fixes are welcome.

