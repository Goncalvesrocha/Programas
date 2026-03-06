DELIMITER &&

CREATE PROCEDURE number5()
BEGIN
   SELECT produto.pro_id, COUNT(produto.pro_id) 
   FROM produto JOIN itempedido ON
	    itempedido.pro_id = produto.pro_id JOIN pedido ON
		pedido.ped_id = itempedido.ped_id
   WHERE ped_data <= "2022-06-30" AND
		 ped_data >= "2022-01-01" 
   GROUP BY produto.pro_id
   HAVING COUNT(produto.pro_id) > 5;

END &&

DELIMITER ;

CALL number5();

-------------------------------------------------

DELIMITER &&

CREATE PROCEDURE top10Vendedores()
BEGIN
   SELECT vendedor.ven_cpf, vendedor.ven_nome, SUM(pedido.ped_valorTotal) as total_vendas 
   FROM vendedor
   JOIN pedido ON vendedor.ven_cpf = pedido.ven_cpf
   WHERE ped_data LIKE "2021%"
   GROUP BY vendedor.ven_cpf, vendedor.ven_nome
   ORDER BY SUM(pedido.ped_valorTotal) DESC
   LIMIT 10;
END &&

DELIMITER ;

CALL top10vendedores();

-------------------------------------------------

DELIMITER &&

CREATE PROCEDURE VendedoresPorRegiao()
BEGIN
   SELECT regiao.reg_nome, count(vendedor.ven_cpf) 
   FROM vendedor
   JOIN regiao ON vendedor.reg_id = regiao.reg_id
   GROUP BY regiao.reg_nome
   ORDER BY regiao.reg_nome;
END &&

DELIMITER ;

CALL VendedoresPorRegiao();


-------------------------------------------------

DELIMITER &&

CREATE PROCEDURE Ultimos3meses()
BEGIN
	SELECT pro_id, pro_nome
	FROM produto
	WHERE pro_id NOT IN (SELECT DISTINCT produto.pro_id
	                     FROM produto
	                     JOIN itempedido ON produto.pro_id = itempedido.pro_id
						 JOIN pedido ON pedido.ped_id = itempedido.ped_id
						 WHERE ped_data BETWEEN "2025-04-01" AND "2025-06-30"
	                    ); 

END &&

DELIMITER ;

CALL Ultimos3meses();

-------------------------------------------------

DELIMITER &&

CREATE PROCEDURE ClienteHistorico(IN cli_cnpj varchar(20))

BEGIN
	SELECT cliente.cli_nome, pedido.ped_id, pedido.ped_data, produto.pro_descricao 
	FROM pedido 
	JOIN itempedido ON itempedido.itp_id = pedido.itp_id
	JOIN cliente ON cliente.cli_id = pedido.cli_id 
	JOIN produto ON produto.pro_id = itempedido.pro_id
    WHERE cliente.cli_nome = cli_cnpj
	ORDER BY cliente.cli_nome, pedido.ped_data;
END &&

DELIMITER ;

CALL ClienteHistorico("12.345.678/0001-90");