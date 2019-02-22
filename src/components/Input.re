let component = ReasonReact.statelessComponent("Input");

let make = (~value, ~onInputText, ~submit, _children) => {
  ...component,
  render: _self =>
    <div className="input">
      <input
        value
        placeholder="Enter item and click add"
        onChange={evt =>
          onInputText(
            ReactDOMRe.domElementToObj(ReactEventRe.Form.target(evt))##value,
          )
        }
      />
      <button onClick={_ => submit()}> {ReasonReact.string("Add")} </button>
    </div>,
};