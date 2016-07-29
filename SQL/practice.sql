select cast(sum(LAT_N) as Decimal(10, 4)) from STATION where LAT_N between 38.7880 and 137.2345;
select round(sum(LAT_N), 4) from STATION where LAT_N between 38.7880 and 137.2345;
select cast(LAT_N as decimal(10,4)) from STATION where LAT_N < 137.2345 order by LAT_N DESC limit 1;
select round(LAT_N,4) from STATION where LAT_N < 137.2345 order by LAT_N DESC limit 1;
select round(LONG_W, 4) from STATION where LAT_N < 137.2345 order by LAT_N DESC limit 1;
select cast(LAT_N, decimal(10,4)) from STATION where LAT_N > 38.7880 order by LAT_N limit 1;

#2016-06-17
select cast(LONG_W as decimal(10,4)) from STATION where LAT_N > 38.7780 order by LAT_N limit 1;
select round(abs(max(LAT_N) - max(LONG_W)) abs(min(LAT_N) - min(LONG_W)),4) from STATION;
select round(sqrt((min(LAT_N) - min(LONG_W)) * (min(LAT_N) - min(LONG_W)) + (max(LAT_N) - max(LONG_W)) * (max(LAT_N) - max(LONG_W))),4) from STATION;
select round(LAT_N, 4) from STATION s where (select count(LAT_N) from STATION where LAT_N < s.LAT_N) = (select count(LAT_N) from STATION where LAT_N > s.LAT_N);
select ceil(avg(Salary) - avg(replace(Salary,'0',''))) from EMPLOYEES;
select s.Name from Students s, Friends f, Packages p1, Packages p2 where (s.ID = f.ID and f.ID = p1.ID and f.Friend_ID = p2.ID and p1.Salary < p2.Salary) order by p2.Salary;
SELECT DISTINCT F.X, F.Y FROM Functions F INNER JOIN Functions F1 ON F.X = F1.Y AND F1.X = F.Y WHERE F.X < F.Y UNION SELECT F.X,F.Y FROM Functions F GROUP BY F.X,F.Y HAVING COUNT(*) > 1 ORDER BY 1;

#2016-06-25
