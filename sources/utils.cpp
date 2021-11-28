// Copyright 2021 vlados2003

#include <header.hpp>
json getJSON(int argc, char** argv) {
  if (argc < 2) throw std::runtime_error{"The file path was not passed"};
  std::string filePath(argv[1]);
  std::ifstream jsonFile(filePath);
  if (!jsonFile) throw std::runtime_error{"unable to open json: " + filePath};
  json data;
  jsonFile >> data;

  if (!data.at("items").is_array())
    throw std::runtime_error{"the array must be contained in the file"};

  if (data.at("items").size() != data.at("_meta").at("count").get<size_t>())
    throw std::runtime_error{"_meta value does not match the array size"};
  return data;
}
