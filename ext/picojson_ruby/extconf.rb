require "mkmf"

#$CFLAGS << %[ ]

have_library("stdc++")
create_makefile("picojson_ruby/picojson_ruby")
