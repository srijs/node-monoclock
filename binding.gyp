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
      ],
      "cflags": [
        "-std=c++11"
      ],
      "conditions": [
        [
          "OS==\"mac\"",
          {
            "xcode_settings": {
              "OTHER_CPLUSPLUSFLAGS": [
                "-std=c++11",
                "-stdlib=libc++"
              ],
              "OTHER_LDFLAGS": [
                "-stdlib=libc++"
              ],
              "MACOSX_DEPLOYMENT_TARGET": "10.7"
            }
          }
        ]
      ]
    }
  ]
}
