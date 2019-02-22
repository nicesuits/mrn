[%bs.raw {|require('./app.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div className="App">
      <h1> {ReasonReact.string("Hello world!!")} </h1>
      <div className="App-intro"> <Todo /> </div>
    </div>,
};