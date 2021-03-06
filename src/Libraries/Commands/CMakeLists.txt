PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS
  ${CMAKE_SRC_DIR}/Libraries/Commands/commands.proto
  ${CMAKE_SRC_DIR}/Libraries/Commands/list_messages.proto
  ${CMAKE_SRC_DIR}/Libraries/Commands/set_messages.proto
  ${CMAKE_SRC_DIR}/Libraries/Commands/types.proto
)

PROTOBUF_GENERATE_GRPC_CPP(GRPC_SRCS GRPC_HDRS
  ${CMAKE_SRC_DIR}/Libraries/Commands/commands.proto
)

#disable unused parameter warning only for GRPC_SRCS
set_source_files_properties(${GRPC_SRCS} PROPERTIES COMPILE_FLAGS -Wno-unused-parameter)

add_library (oktoplus_commands SHARED
  ${PROTO_SRCS}
  ${GRPC_SRCS}
  ${CMAKE_SRC_DIR}/Libraries/Commands/commands_client.cpp
  ${CMAKE_SRC_DIR}/Libraries/Commands/commands_deque.cpp
  ${CMAKE_SRC_DIR}/Libraries/Commands/commands_list.cpp
  ${CMAKE_SRC_DIR}/Libraries/Commands/commands_set.cpp
  ${CMAKE_SRC_DIR}/Libraries/Commands/commands_server.cpp
  ${CMAKE_SRC_DIR}/Libraries/Commands/commands_vector.cpp
)

target_link_libraries (oktoplus_commands
  oktoplus_storage
  ${GLOG}
  ${PROTOBUF_LIBRARIES}
  ${GRPC_LIBRARIES}
)
