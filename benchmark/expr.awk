BEGIN {
  if (!base) base = 2000000

  for (i=0; i<base; i++)
    x = "hello" (i + (30 - (i % 30)))-30 "-" (i + (30 - (i % 30)))-1
}
