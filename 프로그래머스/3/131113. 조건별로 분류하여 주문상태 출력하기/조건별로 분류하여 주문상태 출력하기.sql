SELECT ORDER_ID, PRODUCT_ID, DATE_FORMAT(OUT_DATE,'%Y-%m-%d'),
CASE WHEN DATEDIFF(OUT_DATE,'20220501')>0 THEN '출고대기'
WHEN ISNULL(OUT_DATE) THEN '출고미정'
ELSE '출고완료'
END AS '출고여부'
FROM FOOD_ORDER
ORDER BY ORDER_ID ASC;