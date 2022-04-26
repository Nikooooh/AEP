<?php 

include __DIR__ , '/../vendor/autoload.php';
use Dados\Estilos;

$estilosRepository = new \Dados\Estilos();
$estilos = $estilosRepository->listarEstilos();
$estilos = array_map(function($item){
  return[
    'codigo' => $item['cod_estilo'],
    'estilo' => $item['estilo']
   ];
  }, $estilos);
  
  print json_encode($estilos, JSON_PRETTY_PRINT);
