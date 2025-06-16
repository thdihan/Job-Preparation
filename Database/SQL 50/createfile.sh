#!/bin/bash

# Check if argument is provided
if [ -z "$1" ]; then
  echo "Usage: $0 \"<problem title>\""
  exit 1
fi

# Original input string
input="$1"

# Create a filename by replacing dot and space with underscores
filename=$(echo "$input" | sed -E 's/[. ]+/_/g').md

# Create the markdown file with a basic template
cat <<EOF > "$filename"
### $input

[Link]()

\`\`\`sql
\`\`\`
EOF

echo "File '$filename' created successfully!"

# Append a reference entry to README.md if not already present
entry="- [$input]()"

# Check if entry already exists in README.md
if ! grep -Fxq "$entry" README.md; then
  echo "$entry" >> README.md
  echo "Entry added to README.md"
else
  echo "Entry already exists in README.md"
fi
