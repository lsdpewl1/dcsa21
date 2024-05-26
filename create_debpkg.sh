mkdir -p ./deb_pakage
mkdir -p ./deb_pakage/bin
mkdir -p ./deb_pakage/DEBIAN
touch  ./deb_pakage/DEBIAN/control

cat << EOF > ./deb_pakage/DEBIAN/control
Package: http-server-client-dcsa
Version: 1.0
Architecture: amd64
Maintainer: Someone
Description: client server for labs3
EOF

cp ./build/http-server ./deb_pakage/bin/
cp ./build/http-client ./deb_pakage/bin/
cp ./build/http-client-test ./deb_pakage/bin/

dpkg-deb --build ./deb_pakage/ http-server-client-dcsa.deb