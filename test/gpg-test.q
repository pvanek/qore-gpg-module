#!/usr/bin/env qore

%requires gpg

my string $text = "Lorem ipsum\n\n";

my binary $enc;

# non existing key test
/*
try {
    $enc = gpg_encrypt($text, ("foo@bar.com",));
}
catch ($ex) {
    printf("Expected error: %n\n", $ex);
}
*/

$enc = gpg_encrypt($text, ("petr.vanek@qoretechnologies.com",));
printf("%y\n", $enc);
#my File $f();
#$f.open2("encrypted.txt.gpg", O_CREAT | O_TRUNC | O_WRONLY, 0644);
#$f.write($enc);

my string $res = gpg_decrypt($enc);
printf("RES> %N\n", $res);


if ($res != $text)
    throw "TEST-ERROR", "strings do not match";
printf("test: OK\n");

