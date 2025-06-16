#!/bin/bash

# Check if argument is provided
if [ -z "$1" ]; then
  echo "Usage: $0 \"<problem title>\""
  exit 1
fi

# Original string
input="$1"

# Filename conversion: replace '.' and space with '_' and add .md
filename=$(echo "$input" | sed -E 's/[. ]+/_/g').md

# Create file with markdown content
cat <<EOF > "$filename"
### $input

[Link]()

\`\`\`sql
\`\`\`
EOF

echo "File '$filename' created successfully!"
