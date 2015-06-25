program test_1;
const 
p = 3;
q = 4;

type
n = integer;
age = array [0 .. 100] of integer;
test = ( one, two, three );
books = record
    title: array [1..50] of char;
    author: array [1..50] of char;
    book_id: integer;
end;

var
    weekdays, holidays : integer;
    zm : age;

function fib(x:integer):integer;
begin
  if ((x = 0) or (x = 1)) then
    fib:=1
  else
    fib:=fib(x - 2) + fib(x - 1);
end;
begin
  n:=read;
  write(fib(n));
end.
