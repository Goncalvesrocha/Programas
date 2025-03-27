CREATE DATABASE Restaurante;
USE Restaurante;


CREATE TABLE IF NOT EXISTS Categoria (
  cat_codigo int primary key,
  cat_nome varchar(20) not null  
); 


CREATE TABLE IF NOT EXISTS Cardapio (
  car_codigo int primary key,
  car_nome varchar(20) not null,
  car_preco decimal(6,2) not null, 
  car_unidade int NOT NULL,
  cat_codigo INt,
  FOREIGN KEY (cat_codigo) REFERENCES Categoria(cat_codigo)
) ;


CREATE TABLE IF NOT EXISTS Cliente (
  cli_codigo INT PRIMARY KEY,
  cli_cpf VARCHAR(14) UNIQUE NOT NULL, 
  cli_nome VARCHAR(45) NOT NULL,
  cli_dataNascimento DATE NOT NULL,
  cli_email VARCHAR(35) UNIQUE NOT NULL,
  cli_telefone VARCHAR(14) NOT NULL
);


CREATE TABLE IF NOT EXISTS FormaPagamento (
  for_id INT PRIMARY KEY, /* 0 - Dinheiro; 1 - Débito; 2 - Crédito, 3 - Pix, 4 - Multiformas*/
  for_forma VARCHAR(24) not null /*se for escolhida o número 4, digitar as duas ou mais formas de pagamento envolvidas*/
) ;


CREATE TABLE IF NOT EXISTS Pedido (
  ped_numeroVenda INT AUTO_INCREMENT PRIMARY KEY, /* Incrementa de forma automatica*/
  ped_data DATE NOT NULL,
  ped_valorTotal DECIMAL(8,2) NOT NULL,
  ped_numeroPessoas INT NOT NULL,
  cli_codigo INT,
  for_id INT,
  FOREIGN KEY (cli_codigo) REFERENCES Cliente(cli_codigo),
  FOREIGN KEY (for_id) REFERENCES FormaPagamento(for_id)
) ;


CREATE TABLE IF NOT EXISTS Garcom (
  gar_codigo INT PRIMARY KEY,
  gar_nome VARCHAR(40) NOT NULL,
  gar_horarioTrabalho VARCHAR(15) NOT NULL
) ;


CREATE TABLE IF NOT EXISTS ItemPedido (
  itp_numeroItem INT PRIMARY KEY,
  itp_quantidade INT not null,
  itp_valorUnitario decimal(8,2) not NULL,
  itp_valorTotalItem DECIMAL(8,2) NOT NULL,
  car_codigo INT,
  ped_numeroVenda INT,
  gar_codigo INT,
  FOREIGN KEY (car_codigo) REFERENCES Cardapio(car_codigo),
  FOREIGN KEY (ped_numeroVenda) REFERENCES Pedido(ped_numeroVenda),
  FOREIGN KEY (gar_codigo) REFERENCES Garcom(gar_codigo)
) ;

INSERT INTO Categoria(cat_codigo, cat_nome)
VALUES
(1, "Doces"),
(2, "Salgados"),
(3, "Bebidas"),
(4, "Porção"),
(5, "Pratos");

INSERT INTO Cardapio(car_codigo, car_nome, car_preco, car_unidade, cat_codigo)
VALUES
(50, "Peixe a milanesa", 28.90, 1, 5),
(40, "Costela", 40.00, 1, 4),
(51, "Frango grelhado", 24.99, 1, 5),
(30, "Suco de laranja", 8.00, 1, 3),
(41, "Lasanha", 32.50, 1, 4),
(20, "Coxinha", 6.00, 1, 2),
(10, "Torta de Limão", 12.00, 1, 1),
(31, "Refrigerante Lata", 5.50, 1, 3),
(42, "Batata Frita", 22.00, 1, 4);

INSERT INTO Cliente(cli_codigo, cli_cpf, cli_nome, cli_dataNascimento, cli_email, cli_telefone)
VALUES
(1, "374.829.650-22", "Rogerio Andrade", "2002-03-07", "rogerioandrade@gmail.com", "11 986702091"),
(2, "518.406.237-91", "Lucas Igor", "2005-01-21", "igãoLcs1@gmail.com",  "15 93650209"),
(3, "692.135.408-06", "Matheus Renan", "1998-05-05", "MatheusRRR@gmail.com",  "18 96222421" ),
(4, "857.320.194-73", "Ijacir Silva ", "1990-09-21", "Ijaciremail4@gmail.com", "02 972423210" ),
(5, "123.456.789-10", "Amanda Souza", "1995-11-12", "amanda@gmail.com", "11 978562341"),
(6, "987.654.321-00", "Carlos Mendes", "1988-07-22", "carlos@gmail.com", "21 965412378"),
(7, "741.852.963-45", "Fernanda Rocha", "2000-05-30", "fernandaRocha@gmail.com", "31 982563214"),
(8, "369.258.147-89", "João Pedro", "1993-09-14", "joao.pedro@gmail.com", "44 995874123"),
(9, "258.147.369-75", "Beatriz Lima", "2002-02-18", "beatrizL@gmail.com", "55 987412365");

INSERT INTO FormaPagamento(for_id, for_forma)
VALUES
(0, "Dinheiro"),
(1, "Débito"),
(2, "Crédito"),
(3, "Pix"),
(4, "MultiFormas");

INSERT INTO Pedido(ped_data, ped_valorTotal, ped_numeroPessoas, cli_codigo, for_id)
VALUES
("2025-01-03", 28.90, 1, 1, 2),
("2024-04-08", 56.00, 2, 4, 3),
("2023-09-10", 24.99, 1, 3, 0),
("2025-02-10", 32.50, 1, 5, 1),
("2024-06-15", 48.00, 2, 6, 2),
("2023-12-25", 16.00, 1, 7, 3),
("2024-08-05", 60.00, 3, 8, 0),
("2024-09-21", 45.00, 2, 9, 4),
("2025-03-01", 28.00, 2, 1, 2),
("2024-11-11", 75.00, 4, 2, 1);


INSERT INTO Garcom(gar_codigo, gar_nome, gar_horarioTrabalho)
VALUES
(1, "Rafael Nunes", "19:00 - 23:00"),
(2, "Felipe Oliveira", "18:00 - 00:00"),
(3, "Jaomé Silva Santos", "12:00 - 15:00"),
(4, "Luciana Ferreira", "10:00 - 14:00"),
(5, "Gabriel Souza", "16:00 - 22:00");

INSERT INTO ItemPedido(itp_numeroItem, itp_quantidade, itp_valorUnitario, itp_valorTotalItem, car_codigo, ped_numeroVenda, gar_codigo)
VALUES
(1, 1, 28.90, 28.90, 50, 1, 1),
(2, 2, 40.00, 80.00, 40, 2, 2),
(3, 1, 24.99, 24.99, 51, 3, 3),
(4, 2, 8.00, 16.00, 30, 2, 2),
(5, 1, 32.50, 32.50, 41, 4, 4),
(6, 2, 6.00, 12.00, 20, 5, 5),
(7, 1, 12.00, 12.00, 10, 6, 1),
(8, 3, 5.50, 16.50, 31, 7, 2),
(9, 2, 22.00, 44.00, 42, 8, 3),
(10, 1, 40.00, 40.00, 40, 9, 4);

SELECT * FROM FormaPagamento;
SELECT * FROM Pedido;
SELECT * FROM Cliente;
SELECT * FROM ItemPedido;
SELECT * FROM Garcom;
SELECT * FROM Cardapio;
SELECT * FROM Categoria;



