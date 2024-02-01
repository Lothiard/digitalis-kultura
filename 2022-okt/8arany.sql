SELECT megye.nev, SUM(aerob.letszam) / megye.letszam
FROM megye, aerob
WHERE megye.kod = aerob.mkod
GROUP BY 1
ORDER BY 2 DESC
LIMIT 1;