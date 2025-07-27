#!/bin/bash

echo "🔧 Building the project..."
make
if [ $? -ne 0 ]; then
  echo "❌ Build failed."
  exit 1
fi

echo "🚀 Installing to /usr/local/bin (requires sudo)..."
sudo make install
if [ $? -eq 0 ]; then
  echo "✅ spot installed successfully!"
  echo "👉 You can now run 'spot' from anywhere in your terminal."
else
  echo "❌ Installation failed."
fi
