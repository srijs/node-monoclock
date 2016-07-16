{
  "targets": [
    {
      "target_name": "addon",
      "sources": [
        "addon.cc"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "<(node_root_dir)/deps/openssl/openssl/include",
        "/usr/local/include"
      ],
      "library_dirs": [
        "/usr/local/lib"
      ]
    }
  ]
}
