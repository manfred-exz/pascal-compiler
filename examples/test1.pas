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
  age[10]:= 100;

  write(fib(n));

  case (grade) of
    1 : writeln('Excellent!');
    b : writeln('Well done!');
    c : writeln('You passed');
  end;

  for i := 1 to 10 do
      n := n+1;

  while n < 100
  do 
    n := n+1;

  repeat n := n+1;
  until n = 100;

  goto 3;
  
  if (n = 3) then
      n:=0
  else
      n:=1;
end.
