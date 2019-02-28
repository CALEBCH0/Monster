package(default_visibility = ["//visibility:public"])

cc_library(
  name = "print",
  hdrs = ["monsterPrint.h"],
)

cc_library(
  name = "info",
  hdrs = ["unitInfo.h"],
)

cc_library(
  name = "attack",
  hdrs = ["attack.h"],
  deps = [":info"],
)

cc_binary(
  name = "monster",
  srcs = ["monster.cpp"],
  deps = [
      ":print", 
      ":info",
      ":attack",
  ],
)
