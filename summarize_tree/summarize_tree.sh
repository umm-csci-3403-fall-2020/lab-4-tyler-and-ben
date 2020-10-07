#!/usr/bin/env bash

path="$1"
file_count="$(find "$path" -type f -print | wc -l)"
dir_count="$(find "$path" -type d -print | wc -l)"

echo "There were ""$dir_count"" directories."
echo "There were ""$file_count"" regular files."

