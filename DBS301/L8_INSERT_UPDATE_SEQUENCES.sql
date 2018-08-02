DROP SEQUENCE seq_ProductID_PK;

CREATE SEQUENCE seq_ProductID_PK
START WITH 1
INCREMENT BY 1
NOMAXVALUE
NOCACHE;

INSERT ALL 
    INTO tblVendorLab9(VendorID, VendorName, VendorContact, VendorContactPhone)
    VALUES(1, 'Acme Corp.', 'Bob Smith', '416-555-9087')
    INTO tblVendorLab9(VendorID, VendorName, VendorContact, VendorContactPhone)
    VALUES(2, 'Hewlett Packard', '', '416-555-3234')
SELECT 1 FROM dual;

SELECT * FROM tblVendorLab9;

CREATE FUNCTION get_seq RETURN NUMBER IS
BEGIN
  RETURN seq_ProductID_PK.NEXTVAL;
END;

INSERT ALL
    INTO tblProductLab9(ProductID, VendorID, ProductDesc, ProductCost, ProductSell)
    VALUES(get_seq, 1, 'Dell Mouse', 25, 50)
    INTO tblProductLab9(ProductID, VendorID, ProductDesc, ProductCost, ProductSell)
    VALUES(get_seq, 2, 'HP Pavilion', 230, 670)
    INTO tblProductLab9(ProductID, VendorID, ProductDesc, ProductCost, ProductSell)
    VALUES(get_seq, 1, 'Acer HD Monitor', 55, 128)
SELECT 1 FROM dual;

SELECT * FROM tblProductLab9;

UPDATE tblProductLab9
SET 
    ProductCost = 195,
    ProductSell = 650
WHERE 
    ProductDesc='HP Pavilion';

SELECT last_number FROM user_sequences WHERE sequence_name='SEQ_PRODUCTID_PK';
ALTER SEQUENCE seq_Product_PK INCREMENT BY -2;
INSERT INTO dual VALUES(seq_Product_PK.NEXTVAL);
ALTER SEQUENCE seq_Product_PK INCREMENT BY 1;
SELECT last_number FROM user_sequences WHERE sequence_name='SEQ_PRODUCTID_PK';


