BEGIN {
  if (!base) base = 1500000

  a = 133
  x[a, 458] = 3
  x[a, 459] = 4
  x[a, 460] = 5
  x[a, 461] = 6
  x[a, 462] = 7
  for (i=0; i<base; i++)
  {
    z1 = x[a, 458]
    z2 = x[a, 459]
    z3 = x[a, 460]
    z4 = x[a, 461]
    z5 = x[a, 462]
  }
}
