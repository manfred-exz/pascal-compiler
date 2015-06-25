program test_1;
const 
p = 3;
q = 4;

type
n = integer;
age = array [0 .. 100] of integer;

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
