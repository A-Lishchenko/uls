
int mx_sqrt(int x) {
      double res = x;
      double div = x;
      if (x <= 0)
            return 0;
      while (1) {
            div =  (x / div + div) / 2;
            if (res > div)
                  res = div;
            else
                  if(res - (int) res != 0)
                        return 0;
                  else
                        return res;
      }

}

