USE restaurante;

/*Com uma tabela e ordenação descendente:*/
SELECT cli_nome
FROM cliente
ORDER BY cli_nome DESC;


/*Com duas tabelas relacionadas e ordenação:*/
SELECT *
FROM pedido JOIN cliente ON pedido.cli_codigo = cliente.cli_codigo
ORDER BY cli_nome;


/*Com duas tabelas, condições e ordenação:*/
SELECT *
FROM cardapio JOIN categoria ON cardapio.cat_codigo = categoria.cat_codigo
WHERE car_preco > 19.00
ORDER BY car_preco; 


/*Com mais de uma tabela, distinct e agrupamento:*/
SELECT DISTINCT cliente.cli_nome
FROM cliente
JOIN pedido ON cliente.cli_codigo = pedido.cli_codigo
GROUP BY cliente.cli_nome;

SELECT cli_nome, SUM(ped_valorTotal) AS 'TOTAL GASTO'
FROM cliente JOIN pedido ON cliente.cli_codigo = pedido.cli_codigo
GROUP BY cli_nome;


/*Com três tabelas ou mais tabelas, condição, agrupamento, distinct e having:*/
SELECT DISTINCT cliente.cli_nome
FROM cliente
JOIN pedido ON cliente.cli_codigo = pedido.cli_codigo
JOIN itempedido ON pedido.ped_numeroVenda = itp_numeroItem
GROUP BY cliente.cli_nome
HAVING SUM(pedido.ped_valorTotal) > 5;


/*Com todas as tabelas:*/
SELECT *
FROM cliente
JOIN pedido ON cliente.cli_codigo = pedido.cli_codigo
JOIN formapagamento ON pedido.for_id = formapagamento.for_id
JOIN itempedido ON pedido.ped_numeroVenda = itempedido.ped_numeroVenda
JOIN cardapio ON itempedido.car_codigo = cardapio.car_codigo
JOIN categoria ON cardapio.cat_codigo = categoria.cat_codigo
JOIN garcom ON itempedido.gar_codigo = garcom.gar_codigo;


/*Com mais de duas tabelas agrupamento e contagem (ou somatório):*/
SELECT cliente.cli_nome, COUNT(itempedido.itp_numeroItem) AS total_produtos
FROM cliente
JOIN pedido ON cliente.cli_codigo = pedido.cli_codigo
JOIN itempedido ON pedido.ped_numeroVenda = itempedido.ped_numeroVenda
GROUP BY cliente.cli_nome
ORDER BY total_produtos DESC;


/*Com várias tabelas, condição e subselect:*/
SELECT cliente.cli_nome, pedido.ped_valorTotal
FROM cliente
JOIN pedido ON cliente.cli_codigo=pedido.cli_codigo
WHERE pedido.ped_valorTotal > (SELECT AVG(ped_valorTotal)
								FROM pedido);













