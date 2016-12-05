<?php

function fetchAllFoto($connectDB){
	$arrayFoto = array();

	$sqlQuery = "SELECT * FROM t_galeria";
	$sqlResult = mysqli_query($connectDB, $sqlQuery);
	$numRows = mysqli_num_rows($sqlResult);
	if($numRows > 0){
			while($oneFoto = mysqli_fetch_assoc($sqlResult)){
					$arrayFoto[] = $oneFoto;
			}
			return $arrayFoto;
	}else{
			return 0; // "Brak zdjęć w galerii";
	}
};

function getOnePhoto($connectDB, $id_foto){
	$sqlQuery = "SELECT tytul_foto, nazwaPliku_foto FROM t_galeria WHERE id_foto =" . $id_foto;
	//echo $sqlQuery;
	$sqlResult = mysqli_query($connectDB, $sqlQuery);
	$numRows = mysqli_num_rows($sqlResult);
	if($numRows > 0){
			//$oneFoto =  //pobranie rekordu jednego zdjecia w postaci tablicy asocjacyjnej
					//return $oneFoto; //tablica z jednym zdjeciem
					return mysqli_fetch_assoc($sqlResult);
	}else{
			return 0; //brak zdjec
	}
};
 ?>
