USE DB2025v2

-- ==========================
-- EJERCICIOS
-- ==========================

-- 1. Listar todos los clientes con su nombre, dirección y email.
SELECT Nombre, Direccion, Email FROM Clientes

-- 2. Listar los artículos cuyo stock sea menor a 15 unidades.
SELECT * FROM Articulos WHERE Stock < 15; 

-- 3. Listar todos los pedidos mostrando el número de pedido, la fecha, el nombre del cliente y el total
SELECT PedidoID, Fecha, Total FROM PedidosCabecera
	INNER JOIN Clientes ON (Clientes.ClienteID = PedidosCabecera.ClienteID)

-- 4. Mostrar el detalle del pedido con ID = 3 (artículos, cantidades y subtotal).
SELECT Descripcion, Cantidad, Subtotal FROM PedidosDetalle
	INNER JOIN Articulos ON (Articulos.ArticuloID = PedidosDetalle.ArticuloID)
WHERE PedidoID = 3

-- 5. Mostrar cada artículo con la cantidad total vendida y el monto total vendido.
SELECT Articulos.ArticuloID, Articulos.Descripcion,
	SUM(PedidosDetalle.Cantidad) AS CantidadTotalVendida,
	SUM(PedidosDetalle.Subtotal) AS MontoTotalVendido

FROM Articulos
	INNER JOIN PedidosDetalle ON (Articulos.ArticuloID = PedidosDetalle.ArticuloID)
GROUP BY Articulos.ArticuloID, Articulos.Descripcion;

-- 6. Listar los pedidos mayores a $200.000 indicando cliente, número de pedido y total.
SELECT C.Nombre AS Cliente, p.PedidoID, p.Total FROm PedidosCabecera AS P
	INNER JOIN Clientes AS C ON (p.ClienteID = c.ClienteID)
WHERE p.Total > 200000

-- 7. Mostrar cada cliente con la cantidad de pedidos que realizó.
SELECT  c.ClienteID,
        c.Nombre,
        COUNT(pc.PedidoID) AS CantidadPedidos
FROM Clientes c
LEFT JOIN PedidosCabecera pc ON pc.ClienteID = c.ClienteID
GROUP BY c.ClienteID, c.Nombre

-- PAra que el cliente 3 tenga 2 pedidos y el clietne 2 no tenga pedidos
UPDATE PedidosCabecera SET ClienteID = 3 WHERe PedidosCabecera.PedidoID = 2

-- 8. Mostrar el pedido más caro indicando su número, el cliente y el total.
SELECT TOP 1 PedidosCabecera.PedidoID, Clientes.Nombre, PedidosCabecera.Total
	FROM PedidosCabecera 
INNER JOIN Clientes ON PedidosCabecera.ClienteID = Clientes.ClienteID
ORDER BY PedidosCabecera.Total DESC

-- 9. Listar los artículos que aparecen en más de un pedido, indicando en cuántos pedidos distintos se vendió cada uno.
SELECT  a.ArticuloID,
        a.Descripcion,
        COUNT(DISTINCT pd.PedidoID) AS PedidosDistintos
FROM PedidosDetalle pd
JOIN Articulos a ON a.ArticuloID = pd.ArticuloID
GROUP BY a.ArticuloID, a.Descripcion
HAVING COUNT(DISTINCT pd.PedidoID) > 1

-- 10. Mostrar las ventas totales agrupadas por mes y año.
SELECT  YEAR(pc.Fecha)  AS Anio,
        MONTH(pc.Fecha) AS Mes,
        SUM(pc.Total)   AS VentasTotales
FROM PedidosCabecera pc
GROUP BY YEAR(pc.Fecha), MONTH(pc.Fecha)